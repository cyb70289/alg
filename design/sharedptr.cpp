#include <iostream>

using namespace std;

class shared_ptr
{
private:
    int *ptr;
    int *refcnt;

    void addref(void)
    {
        (*refcnt)++;
    }

    void decref(void)
    {
        (*refcnt)--;
        if (*refcnt == 0) {
            delete refcnt;
            delete ptr;
        }
    }

public:
    shared_ptr(int *ptr)
    {
        this->ptr = ptr;
        this->refcnt = new int;
        *(this->refcnt) = 1;
    }

    shared_ptr(const shared_ptr &sptr)
    {
        this->ptr = sptr.ptr;
        this->refcnt = sptr.refcnt;
        addref();
    }

    ~shared_ptr()
    {
        decref();
    }

    const int *getptr(void)
    {
        return ptr;
    }
};

int main(void)
{
    int *ptr = new int[10]();
    ptr[0] = 999;

    shared_ptr *sptr = new shared_ptr(ptr);
    cout << sptr->getptr()[0] << endl;

    shared_ptr sptr2 = *sptr;

    delete sptr;

    cout << ptr[0] << endl;

    return 0;
}
