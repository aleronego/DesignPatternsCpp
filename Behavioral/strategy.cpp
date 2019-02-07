#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Compression
{
public:
    virtual ~Compression() = default;
    virtual void compress(const string& file) = 0;
};

class Zip : public Compression
{
public:
    void compress(const string& file) override
    {
        cout << "Zip compression file: " << file << endl;
    }
};

class Rar : public Compression
{
public:
    void compress(const string& file) override
    {
        cout << "Rar compression file: " << file << endl;
    }
};

class Compressor
{
shared_ptr<Compression> comp_ptr;
public:
    Compressor(shared_ptr<Compression> comp_out) : comp_ptr( std::move(comp_out) ) {}
    void compress(const string& file)
    {
        comp_ptr->compress(file);
    }
};

int main(int argc, char const *argv[])
{
     auto cRar = make_shared<Compressor>( make_shared<Rar>() );
     cRar->compress("someFile.txt");

    auto cZip = make_shared<Compressor>( make_shared<Zip>() );
    cZip->compress("someFile.txt");
    return 0;
}