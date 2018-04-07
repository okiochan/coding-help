struct pt {
    double  x, y;
    pt() {}
    pt(double x, double y) :x(x), y(y) {}

    double norm() { return sqrt(x*x+y*y); }
    void read() { cin >> x >> y; }
    void sout() { cout << x << " " << y << endl; }
    pt e() { return *this / norm(); }

    pt operator+(pt p) const { return pt(x+p.x, y+p.y); }
    pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
    pt operator*(double d) const { return pt(x * d, y * d); }
    pt operator/(double d) const { return pt(x / d, y / d); }
    double operator*(pt p) const { return x*p.x+y*p.y; } //scalar
    pt operator ~() const { return pt(-y, x); }  //normal
    double operator%(pt p) const { return (*this)*(~p);} //vector
    
};

pt intersectLine(pt a, pt b, pt c, pt d) {
    double t = -(~(d - c)*(a - c)) / (~(d - c)*(b - a));
    return (b - a)*t + a;
}

double len(pt a, pt b) {
    return (b - a).norm();
}


void intersetCircle(pt c, double r, pt a, pt b) {

    pt x = (b - a).e()* ((c - a)*(b - a) / (b - a).norm()) + a;

    if (r*r - len(c, x)*len(c, x) < 0) {
        cout << "no" << endl;
        return;
    }
    double yx = sqrt(r*r - len(c, x)*len(c, x));

    pt y1 = (b - a).e() * yx + x;
    pt y2 = (a - b).e() * yx + x;

    y1.sout(); y2.sout();
}