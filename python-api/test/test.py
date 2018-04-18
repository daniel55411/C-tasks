import ref
import sys

def test_1():
    a = []
    b = a
    c = a
    return ref.count(a) == sys.getrefcount(c)

def test_2():
    a = "asduniq"
    return ref.count(a) == sys.getrefcount(a)

def test_3():
    a = b"111"
    return ref.count(a) == sys.getrefcount(a)

if __name__ == '__main__':
    assert test_1()
    assert test_2()
    assert test_3()
    print("Tests is completed")
