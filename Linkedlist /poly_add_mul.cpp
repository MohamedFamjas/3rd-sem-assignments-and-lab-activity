#include <iostream>
using namespace std;

struct Term { int coef, exp; Term* next; };

// Insert a term keeping the list sorted by exponent (descending);
// if the exponent already exists, the coefficients are added.
void insertTerm(Term*& h, int c, int e) {
    if (c == 0) return;
    if (!h || e > h->exp) { h = new Term{c, e, h}; return; }
    Term* t = h;
    while (t->next && t->next->exp > e) t = t->next;
    if (t->exp == e) { t->coef += c; return; }
    if (t->next && t->next->exp == e) { t->next->coef += c; return; }
    t->next = new Term{c, e, t->next};
}

Term* readPoly() {
    Term* h = NULL;
    int n, c, e;
    cout << "Number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Coefficient and exponent: ";
        cin >> c >> e;
        insertTerm(h, c, e);
    }
    return h;
}

void show(Term* h) {
    if (!h) { cout << "0\n"; return; }
    for (Term* t = h; t; t = t->next) {
        cout << t->coef << "x^" << t->exp;
        if (t->next) cout << " + ";
    }
    cout << endl;
}

Term* add(Term* p, Term* q) {
    Term* r = NULL;
    for (Term* t = p; t; t = t->next) insertTerm(r, t->coef, t->exp);
    for (Term* t = q; t; t = t->next) insertTerm(r, t->coef, t->exp);
    return r;
}

Term* multiply(Term* p, Term* q) {
    Term* r = NULL;
    for (Term* a = p; a; a = a->next)
        for (Term* b = q; b; b = b->next)
            insertTerm(r, a->coef * b->coef, a->exp + b->exp);
    return r;
}

int main() {
    cout << "First polynomial\n";  Term* p = readPoly();
    cout << "Second polynomial\n"; Term* q = readPoly();
    cout << "P1      = "; show(p);
    cout << "P2      = "; show(q);
    cout << "Sum     = "; show(add(p, q));
    cout << "Product = "; show(multiply(p, q));
    return 0;
}