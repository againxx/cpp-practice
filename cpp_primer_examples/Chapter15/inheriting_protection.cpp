class Base {
public:
    void pub_mem() {}
private:
    void pri_mem() {}
protected:
    void prot_mem() {}
};

class PublicDerivated : public Base {
    void memf(Base& b) {
        b = *this;
    }
};

class PrivateDerivated : private Base {
    void memf(Base& b) {
        b = *this;
    }
};

class ProtectedDerivated : protected Base {
    void memf(Base& b) {
        b = *this;
    }
};

class DerivatedFromPublic : public PublicDerivated {
    void memf(Base& b) {
        b = *this;
    }
};

class DerivatedFromPrivate : public PrivateDerivated {
    void memf(Base& b) {
        b = *this;
    }
};

class DerivatedFromProtected : protected ProtectedDerivated {
    void memf(Base& b) {
        b = *this;
    }
};

int main() {
    PrivateDerivated priDeri;
    ProtectedDerivated protDeri;
    PublicDerivated pubDeri;

    DerivatedFromPrivate fromPriv;
    DerivatedFromPublic fromPub;
    DerivatedFromProtected fromProt;

    Base* b = &pubDeri;
    b = &priDeri;
    b = &protDeri;
    b = &fromPub;
    b = &fromProt;
    b = &fromPriv;
    return 0;
}
