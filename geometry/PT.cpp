ld x, y;
PT(ld x = 0, ld y = 0): x(x), y(y) {}


PT operator + (const PT P){
	return PT(x + P.x, y + P.y); }

PT operator - (const PT P){
	return PT(x - P.x, y - P.y); }

PT operator * (const ld d) {
	return PT(x*d, y*d); }

PT operator / (const ld d) {
	return PT(x/d, y/d); }

ld operator * (const PT P){
	return x*P.x + y*P.y;}

ld operator ^ (const PT P){
	return x*P.y - y*P.x;}

ld dist() {
	return sqrt(x*x+y*y); }

ld angle() {
	ld a = atan2l(y, x);
	if (a < 0) a += 2*PI;
	return a;
}


ld dist_between_points(PT p, PT q) {
	return (p - q).dist();
}

// Point C on Line A, B ?
// if point on line == 0
// if the point is to the left > 0
// if the point is to the right < 0
bool point_on_the_line(PT c, PT a, PT b) {
	return ((c - a) ^ (b - a) == 0);
}

// Line A, B parallel to Line C, D?
bool parallel(PT A, PT B, PT C, PT D) {
	return ((B - A) ^ (C - D) == 0);
}

// Point P inside circle C
bool point_on_the_circle(PT P, PT C) {
	return ((C - P).dist() <= 0);
}

ld triangle_area(PT A, PT B, PT C) {
	return abs((B - A) ^ (C - A)) / 2;
}

bool point_on_the_triangle(PT A, PT B, PT C, PT P) {
	PT AB = B - A;
	PT BC = C - B;
	PT CA = A - C;

	PT AP = P - A;
	PT BP = P - B;
	PT CP = P - C;

	ld c1 = AB ^ AP;
	ld c2 = BC ^ BP;
	ld c3 = CA ^ CP;

	return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0); //anti h
}

