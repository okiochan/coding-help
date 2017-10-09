double getS( double d, double r1, double r2)
{

	if(r1 + r2 > d)
	{
		double minR = min(r1,r2), maxR = max(r1,r2);

		if((d + minR >= maxR) && d != 0)
		{
			double qr1, qr2, x, y, h, l, qd;

			 qr1 = r1*r1, qr2 = r2*r2; qd = d*d;
			 x = (qd+qr1-qr2)/(2*d);
		     y = d-x; h = r1-x;
			 l = 2*sqrt(h*(2*r1-h));
			 return ( qr1*acos(x/r1) - x*l*0.5 + qr2*acos(y/r2) - y*l*0.5 );

		}

		return M_PI*minR*minR;
	}

	return 0;
}