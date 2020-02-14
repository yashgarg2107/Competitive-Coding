// Circle geometry functions.

void circ_line_inter(line<db> l1, db x1, db y1, db r, bool is_line_offset) {
    db a = l1.a, b = l1.b, c = l1.c;
    // Line trasnslation wrt center of circle.
    if(!is_line_offset)
    	c = a*x1 + b*y1 + c;

    db x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);

    if (c*c > r*r*(a*a+b*b)+EPS) {
        printf("No Points\n");
    }
    else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        printf("1 point\n");
        // Reverse translation.
        x0 += x1; y0 += y1;
        printf("%.10Lf %.10Lf\n", x0, y0);
    }
    else {
        db d = r*r - c*c/(a*a+b*b);
        db mult = sqrt (d/(a*a+b*b));

        db ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;

        printf("2 points\n");
        // Reverse translation.
        ax += x1; bx += x1; ay += y1; by += y1;
        printf("%.10Lf %.10Lf    %.10Lf %.10Lf\n", ax, ay, bx, by);
    }
}


// Check for degenerate case of same center, if diff radius, no soln,
// if same radius infinite solutions.
void circ_circ_inter(db x1, db y1, db r1, db x2, db y2, db r2) {
	// Translating to shift center of first circle to origin.
	x2 -= x1; y2 -= y1;

	line<db> l1;
	l1.a = -2*x2, l1.b = -2*y2;
	l1.c = x2*x2 + y2*y2 + r1*r1 - r2*r2;

	circ_line_inter(l1, x1, y1, r1, 1);
}