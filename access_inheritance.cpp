#include <iostream>

class CBase
{
  private:
    virtual void test() = 0;
    int privateBase;
  protected:
    int protBase;
  public:
    int pubBase;
};

class CDerived : private CBase
{
    private:
        void test() {
            std::cout << "Private test" << std::endl;
        }
    public:
        void updateDerived()
        {
            protBase=0;
            pubBase=0;
            test();
        }
};

class CDerived1 : private CDerived
{
    public:
        void updateDerived1()
        {
            //privateBase=1; //нельзя доступиться 
                            //к private данным CBase
//             std::cout << "protBase = " << (protBase = 1) << std::endl;
//             std::cout << "pubBase = " << (pubBase = 1) << std::endl;
        }
};

int main() {
    CDerived cd;
    CDerived1 cd1;
    cd.updateDerived();
}
