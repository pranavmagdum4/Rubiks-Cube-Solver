//
// Created by Utkarsh SIngh on 4/20/24.
//
#include "PatternDatabases.h"
using namespace std;

PatternDatabases::PatternDatabases(const size_t size) : database(size,0xFF),size(size),numItems(0){
}

PatternDatabases::PatternDatabases(const size_t size, const uint8_t init_value):database(size,init_value),size(size),numItems(0){
}

bool PatternDatabases::setNumMoves(const uint32_t idx,const uint8_t numMoves)
{
    uint8_t oldMoves=this->getNumMoves(idx);

    if(oldMoves==0xF)
    {
        ++this->numItems;
    }
    if(oldMoves>numMoves)
    {
        this->database.set(idx,numMoves);
        return true;
    }
    return false;
}

bool PatternDatabases::setNumMoves(const RubiksCube &cube, const uint8_t numMoves) {
    return this->setNumMoves(this->getDatabaseIndex(cube),numMoves);
}

uint8_t PatternDatabases::getNumMoves(const RubiksCube &cube) const
{
    return this->database.get(getDatabaseIndex(cube));
}

uint8_t PatternDatabases::getNumMoves(const uint32_t idx) const
{
    return this->database.get(idx);
}

size_t PatternDatabases::getSize() const{
    return this->size;
}

size_t PatternDatabases::getNumItems() const{
    return this->numItems;
}

bool PatternDatabases::isFull() const{
    return this->size==this->numItems;
}

void PatternDatabases::toFile(const string &filePath) const
{
    ofstream writer(filePath ,ios::out|ios::binary|ios::trunc);

    if(!writer.is_open())
        cout<<"Failed to open to write file"<<'\n';

    writer.write(reinterpret_cast<const char*>(this->database.data()),this->database.storageSize());
    writer.close();
}

bool PatternDatabases::fromFile(const string &filePath )
{
    ifstream reader(filePath,ios::in | ios::ate);

    if(!(reader.is_open()))return false;

    size_t fileSize=reader.tellg();

    if((this->database.storageSize())!=fileSize){
        cout<<"Read failed, database corrupt"<<'\n';
        return false;
    }

    reader.seekg(0,ios::beg);

    reader.read(reinterpret_cast<char*>(this->database.data()),this->database.storageSize());
    reader.close();
    this->numItems=this->size;
    return true;
}

vector<uint8_t> PatternDatabases::inflate() const {
    vector<uint8_t> inflated;
    this->database.inflate(inflated);
    return inflated;
}

void PatternDatabases::inflate(vector<uint8_t> &des) const {
    this->database.inflate(des);
}

void PatternDatabases::reset() {
    if(this->numItems)
    {
        this->database.reset(0xFF);
        this->numItems=0;
    }
}