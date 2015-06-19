/*This is mechanically generated code*/
#include <stdlib.h>

#define BORDERS 22

typedef struct {
	int x, y;
} xy;
typedef unsigned char byte;

// Detect if it's a corner or it's not a corner
// b = bstart, so it's the thresholding
// return an array of is_score
int fast9_corner_score(const byte* p, const int pixel[], int bstart) {
	// Valeur de b donné dans le main (Intensité de brightness)
	int bmin = bstart;
	// bmax serait donc à blanc, intensité totale
	int bmax = 255;
	// moyenne de l'intensité
	int b = (bmax + bmin) / 2;

	/*Compute the score using binary search*/
	//IS A CORNER OR IS NOT A CORNER
	for (;;) {
		//Intensity of p + t
		int cb = *p + b;
		//Intensity of p - t
		int c_b = *p - b;

		/**
		 * here we use FAST9 :
		 * If 9 contiguous pixels are brigther than p + b
		 * --> IT'S A CORNER !
		 */
		if (p[pixel[0]] > cb)
			if (p[pixel[1]] > cb)
				if (p[pixel[2]] > cb)
					if (p[pixel[3]] > cb)
						if (p[pixel[4]] > cb)
							if (p[pixel[5]] > cb)
								if (p[pixel[6]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb) // if not, the 15th pixel should be to have a corner
											goto is_a_corner;
										else if (p[pixel[15]] > cb)
											goto is_a_corner;
										else
											// NOT A CORNER, cuz not 9 contiguous pixels
											goto is_not_a_corner;
									else if (p[pixel[7]] < c_b) // DARKER
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[14]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																if (p[pixel[13]]
																		< c_b)
																	if (p[pixel[15]]
																			< c_b)
																		goto is_a_corner;
																	else
																		goto is_not_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[6]] < c_b)
									if (p[pixel[15]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[13]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															if (p[pixel[11]]
																	< c_b)
																if (p[pixel[12]]
																		< c_b)
																	if (p[pixel[14]]
																			< c_b)
																		goto is_a_corner;
																	else
																		goto is_not_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															if (p[pixel[13]]
																	< c_b)
																if (p[pixel[14]]
																		< c_b)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[13]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															if (p[pixel[14]]
																	< c_b)
																if (p[pixel[15]]
																		< c_b)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[5]] < c_b)
								if (p[pixel[14]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																if (p[pixel[11]]
																		> cb)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[12]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															if (p[pixel[11]]
																	< c_b)
																if (p[pixel[13]]
																		< c_b)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[14]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															if (p[pixel[13]]
																	< c_b)
																if (p[pixel[6]]
																		< c_b)
																	goto is_a_corner;
																else if (p[pixel[15]]
																		< c_b)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[6]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															if (p[pixel[13]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															if (p[pixel[11]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[12]] < c_b)
								if (p[pixel[7]] < c_b)
									if (p[pixel[8]] < c_b)
										if (p[pixel[9]] < c_b)
											if (p[pixel[10]] < c_b)
												if (p[pixel[11]] < c_b)
													if (p[pixel[13]] < c_b)
														if (p[pixel[14]] < c_b)
															if (p[pixel[6]]
																	< c_b)
																goto is_a_corner;
															else if (p[pixel[15]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[4]] < c_b)
							if (p[pixel[13]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[11]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[13]] < c_b)
								if (p[pixel[7]] < c_b)
									if (p[pixel[8]] < c_b)
										if (p[pixel[9]] < c_b)
											if (p[pixel[10]] < c_b)
												if (p[pixel[11]] < c_b)
													if (p[pixel[12]] < c_b)
														if (p[pixel[6]] < c_b)
															if (p[pixel[5]]
																	< c_b)
																goto is_a_corner;
															else if (p[pixel[14]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else if (p[pixel[14]]
																< c_b)
															if (p[pixel[15]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[5]] < c_b)
								if (p[pixel[6]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[11]] > cb)
							if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[11]] < c_b)
							if (p[pixel[7]] < c_b)
								if (p[pixel[8]] < c_b)
									if (p[pixel[9]] < c_b)
										if (p[pixel[10]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[6]] < c_b)
														if (p[pixel[5]] < c_b)
															goto is_a_corner;
														else if (p[pixel[14]]
																< c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else if (p[pixel[14]] < c_b)
														if (p[pixel[15]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[3]] < c_b)
						if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[7]] < c_b)
								if (p[pixel[8]] < c_b)
									if (p[pixel[9]] < c_b)
										if (p[pixel[11]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[5]] < c_b)
													if (p[pixel[4]] < c_b)
														goto is_a_corner;
													else if (p[pixel[12]] < c_b)
														if (p[pixel[13]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b)
														if (p[pixel[14]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b)
														if (p[pixel[15]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] > cb)
						if (p[pixel[11]] > cb)
							if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] < c_b)
						if (p[pixel[7]] < c_b)
							if (p[pixel[8]] < c_b)
								if (p[pixel[9]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[5]] < c_b)
													if (p[pixel[4]] < c_b)
														goto is_a_corner;
													else if (p[pixel[13]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													if (p[pixel[15]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[2]] < c_b)
					if (p[pixel[9]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[9]] < c_b)
						if (p[pixel[7]] < c_b)
							if (p[pixel[8]] < c_b)
								if (p[pixel[10]] < c_b)
									if (p[pixel[6]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[4]] < c_b)
												if (p[pixel[3]] < c_b)
													goto is_a_corner;
												else if (p[pixel[11]] < c_b)
													if (p[pixel[12]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[11]] < c_b)
												if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													if (p[pixel[15]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[9]] > cb)
					if (p[pixel[10]] > cb)
						if (p[pixel[11]] > cb)
							if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[3]] > cb)
								if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[9]] < c_b)
					if (p[pixel[7]] < c_b)
						if (p[pixel[8]] < c_b)
							if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[6]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[4]] < c_b)
												if (p[pixel[3]] < c_b)
													goto is_a_corner;
												else if (p[pixel[12]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[1]] < c_b)
				if (p[pixel[8]] > cb)
					if (p[pixel[9]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[2]] > cb)
								if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[8]] < c_b)
					if (p[pixel[7]] < c_b)
						if (p[pixel[9]] < c_b)
							if (p[pixel[6]] < c_b)
								if (p[pixel[5]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[3]] < c_b)
											if (p[pixel[2]] < c_b)
												goto is_a_corner;
											else if (p[pixel[10]] < c_b)
												if (p[pixel[11]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[10]] < c_b)
											if (p[pixel[11]] < c_b)
												if (p[pixel[12]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[10]] < c_b)
										if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[10]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[8]] > cb)
				if (p[pixel[9]] > cb)
					if (p[pixel[10]] > cb)
						if (p[pixel[11]] > cb)
							if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[3]] > cb)
								if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[2]] > cb)
							if (p[pixel[3]] > cb)
								if (p[pixel[4]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[8]] < c_b)
				if (p[pixel[7]] < c_b)
					if (p[pixel[9]] < c_b)
						if (p[pixel[10]] < c_b)
							if (p[pixel[6]] < c_b)
								if (p[pixel[5]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[3]] < c_b)
											if (p[pixel[2]] < c_b)
												goto is_a_corner;
											else if (p[pixel[11]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else
				goto is_not_a_corner;
		else if (p[pixel[0]] < c_b)
			if (p[pixel[1]] > cb)
				if (p[pixel[8]] > cb)
					if (p[pixel[7]] > cb)
						if (p[pixel[9]] > cb)
							if (p[pixel[6]] > cb)
								if (p[pixel[5]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[3]] > cb)
											if (p[pixel[2]] > cb)
												goto is_a_corner;
											else if (p[pixel[10]] > cb)
												if (p[pixel[11]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[10]] > cb)
											if (p[pixel[11]] > cb)
												if (p[pixel[12]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[10]] > cb)
										if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[10]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[8]] < c_b)
					if (p[pixel[9]] < c_b)
						if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[2]] < c_b)
								if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[1]] < c_b)
				if (p[pixel[2]] > cb)
					if (p[pixel[9]] > cb)
						if (p[pixel[7]] > cb)
							if (p[pixel[8]] > cb)
								if (p[pixel[10]] > cb)
									if (p[pixel[6]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[4]] > cb)
												if (p[pixel[3]] > cb)
													goto is_a_corner;
												else if (p[pixel[11]] > cb)
													if (p[pixel[12]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[11]] > cb)
												if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													if (p[pixel[15]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[9]] < c_b)
						if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[2]] < c_b)
					if (p[pixel[3]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[7]] > cb)
								if (p[pixel[8]] > cb)
									if (p[pixel[9]] > cb)
										if (p[pixel[11]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[5]] > cb)
													if (p[pixel[4]] > cb)
														goto is_a_corner;
													else if (p[pixel[12]] > cb)
														if (p[pixel[13]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb)
														if (p[pixel[14]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb)
														if (p[pixel[15]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[3]] < c_b)
						if (p[pixel[4]] > cb)
							if (p[pixel[13]] > cb)
								if (p[pixel[7]] > cb)
									if (p[pixel[8]] > cb)
										if (p[pixel[9]] > cb)
											if (p[pixel[10]] > cb)
												if (p[pixel[11]] > cb)
													if (p[pixel[12]] > cb)
														if (p[pixel[6]] > cb)
															if (p[pixel[5]]
																	> cb)
																goto is_a_corner;
															else if (p[pixel[14]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else if (p[pixel[14]]
																> cb)
															if (p[pixel[15]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[13]] < c_b)
								if (p[pixel[11]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															if (p[pixel[12]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[5]] > cb)
								if (p[pixel[6]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[4]] < c_b)
							if (p[pixel[5]] > cb)
								if (p[pixel[14]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															if (p[pixel[13]]
																	> cb)
																if (p[pixel[6]]
																		> cb)
																	goto is_a_corner;
																else if (p[pixel[15]]
																		> cb)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[14]] < c_b)
									if (p[pixel[12]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															if (p[pixel[11]]
																	> cb)
																if (p[pixel[13]]
																		> cb)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																if (p[pixel[11]]
																		< c_b)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[6]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															if (p[pixel[13]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[5]] < c_b)
								if (p[pixel[6]] > cb)
									if (p[pixel[15]] < c_b)
										if (p[pixel[13]] > cb)
											if (p[pixel[7]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															if (p[pixel[11]]
																	> cb)
																if (p[pixel[12]]
																		> cb)
																	if (p[pixel[14]]
																			> cb)
																		goto is_a_corner;
																	else
																		goto is_not_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															if (p[pixel[13]]
																	> cb)
																if (p[pixel[14]]
																		> cb)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[6]] < c_b)
									if (p[pixel[7]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb)
																if (p[pixel[13]]
																		> cb)
																	if (p[pixel[15]]
																			> cb)
																		goto is_a_corner;
																	else
																		goto is_not_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											goto is_a_corner;
										else if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[13]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															if (p[pixel[14]]
																	> cb)
																if (p[pixel[15]]
																		> cb)
																	goto is_a_corner;
																else
																	goto is_not_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[12]] > cb)
								if (p[pixel[7]] > cb)
									if (p[pixel[8]] > cb)
										if (p[pixel[9]] > cb)
											if (p[pixel[10]] > cb)
												if (p[pixel[11]] > cb)
													if (p[pixel[13]] > cb)
														if (p[pixel[14]] > cb)
															if (p[pixel[6]]
																	> cb)
																goto is_a_corner;
															else if (p[pixel[15]]
																	> cb)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															if (p[pixel[11]]
																	< c_b)
																goto is_a_corner;
															else
																goto is_not_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[11]] > cb)
							if (p[pixel[7]] > cb)
								if (p[pixel[8]] > cb)
									if (p[pixel[9]] > cb)
										if (p[pixel[10]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[6]] > cb)
														if (p[pixel[5]] > cb)
															goto is_a_corner;
														else if (p[pixel[14]]
																> cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else if (p[pixel[14]] > cb)
														if (p[pixel[15]] > cb)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[11]] < c_b)
							if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															goto is_a_corner;
														else
															goto is_not_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] > cb)
						if (p[pixel[7]] > cb)
							if (p[pixel[8]] > cb)
								if (p[pixel[9]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[5]] > cb)
													if (p[pixel[4]] > cb)
														goto is_a_corner;
													else if (p[pixel[13]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													if (p[pixel[15]] > cb)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] < c_b)
						if (p[pixel[11]] < c_b)
							if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														goto is_a_corner;
													else
														goto is_not_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[9]] > cb)
					if (p[pixel[7]] > cb)
						if (p[pixel[8]] > cb)
							if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[6]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[4]] > cb)
												if (p[pixel[3]] > cb)
													goto is_a_corner;
												else if (p[pixel[12]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else if (p[pixel[9]] < c_b)
					if (p[pixel[10]] < c_b)
						if (p[pixel[11]] < c_b)
							if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[3]] < c_b)
								if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												if (p[pixel[8]] < c_b)
													goto is_a_corner;
												else
													goto is_not_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[8]] > cb)
				if (p[pixel[7]] > cb)
					if (p[pixel[9]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[6]] > cb)
								if (p[pixel[5]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[3]] > cb)
											if (p[pixel[2]] > cb)
												goto is_a_corner;
											else if (p[pixel[11]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else if (p[pixel[8]] < c_b)
				if (p[pixel[9]] < c_b)
					if (p[pixel[10]] < c_b)
						if (p[pixel[11]] < c_b)
							if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[3]] < c_b)
								if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[2]] < c_b)
							if (p[pixel[3]] < c_b)
								if (p[pixel[4]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[7]] < c_b)
												goto is_a_corner;
											else
												goto is_not_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else
				goto is_not_a_corner;
		else if (p[pixel[7]] > cb)
			if (p[pixel[8]] > cb)
				if (p[pixel[9]] > cb)
					if (p[pixel[6]] > cb)
						if (p[pixel[5]] > cb)
							if (p[pixel[4]] > cb)
								if (p[pixel[3]] > cb)
									if (p[pixel[2]] > cb)
										if (p[pixel[1]] > cb)
											goto is_a_corner;
										else if (p[pixel[10]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[10]] > cb)
										if (p[pixel[11]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[10]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] > cb)
						if (p[pixel[11]] > cb)
							if (p[pixel[12]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[15]] > cb)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else
				goto is_not_a_corner;
		else if (p[pixel[7]] < c_b)
			if (p[pixel[8]] < c_b)
				if (p[pixel[9]] < c_b)
					if (p[pixel[6]] < c_b)
						if (p[pixel[5]] < c_b)
							if (p[pixel[4]] < c_b)
								if (p[pixel[3]] < c_b)
									if (p[pixel[2]] < c_b)
										if (p[pixel[1]] < c_b)
											goto is_a_corner;
										else if (p[pixel[10]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else if (p[pixel[10]] < c_b)
										if (p[pixel[11]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else if (p[pixel[10]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else if (p[pixel[10]] < c_b)
						if (p[pixel[11]] < c_b)
							if (p[pixel[12]] < c_b)
								if (p[pixel[13]] < c_b)
									if (p[pixel[14]] < c_b)
										if (p[pixel[15]] < c_b)
											goto is_a_corner;
										else
											goto is_not_a_corner;
									else
										goto is_not_a_corner;
								else
									goto is_not_a_corner;
							else
								goto is_not_a_corner;
						else
							goto is_not_a_corner;
					else
						goto is_not_a_corner;
				else
					goto is_not_a_corner;
			else
				goto is_not_a_corner;
		else
			goto is_not_a_corner;

		// TEST IF IT'S A CORNER
		is_a_corner: bmin = b;
		goto end_if;

		// TEST IF IT'S NOT A CORNER
		is_not_a_corner: bmax = b;
		goto end_if;

		// FINISHING THE TEST
		end_if:

		//RETURN AN ARRAY OF THE CORNERS
		if (bmin == bmax - 1 || bmin == bmax)
			return bmin;
		b = (bmin + bmax) / 2;
	}
}

/*
 * Function to give to all the 16 pixels that are part of the circle
 * a value, depending on the row_stride
 */
static void make_offsets(int pixel[], int row_stride) {
	pixel[0] = 0 + row_stride * 3;
	pixel[1] = 1 + row_stride * 3;
	pixel[2] = 2 + row_stride * 2;
	pixel[3] = 3 + row_stride * 1;
	pixel[4] = 3 + row_stride * 0;
	pixel[5] = 3 + row_stride * -1;
	pixel[6] = 2 + row_stride * -2;
	pixel[7] = 1 + row_stride * -3;
	pixel[8] = 0 + row_stride * -3;
	pixel[9] = -1 + row_stride * -3;
	pixel[10] = -2 + row_stride * -2;
	pixel[11] = -3 + row_stride * -1;
	pixel[12] = -3 + row_stride * 0;
	pixel[13] = -3 + row_stride * 1;
	pixel[14] = -2 + row_stride * 2;
	pixel[15] = -1 + row_stride * 3;
}

/**
 * This function will call fast9_corner_score, to give a score to the corner
 * He is a corner or he is not a corner
 */
int* fast9_score(const byte* i, int stride, xy* corners, int num_corners, int b) {
	int* scores = (int*) malloc(sizeof(int) * num_corners);
	int n;

	// Sixteen pixels
	int pixel[16];
	// Give a position depending on the stride of the pixels positionned around
	// the circle, so around the corner
	make_offsets(pixel, stride);

	// For every potential corners, we will know if it's really a corner or not
	// depending on its intensity
	for (n = 0; n < num_corners; n++)
		scores[n] = fast9_corner_score(i + corners[n].y * stride + corners[n].x,
				pixel, b);

	return scores;
}

xy* fast9_detect(const byte* im, int xsize, int ysize, int stride, int b,
		int* ret_num_corners) {
	int num_corners = 0;
	xy* ret_corners;
	int rsize = 512;
	// 16 pixels around the possible corner
	int pixel[16];
	// for loops
	int x, y;

	ret_corners = (xy*) malloc(sizeof(xy) * rsize);
	// Give a position depending on the stride of the pixels positionned around
	// the circle, so around the corner
	make_offsets(pixel, stride);

	for (y = BORDERS; y < ysize - BORDERS; y++)
		for (x = BORDERS; x < xsize - BORDERS; x++) {
			// Here *p is like Ip in the original report for FAST
			// "Machine Learing for high-speed corner detection"
			const byte* p = im + y * stride + x;
			//printf("%d", *p);

			// Ip + threshold
			int cb = *p + b;
			// Ip - threshold
			int c_b = *p - b;
			// This if is for everything brighter
			// FAST 9 is here to test the 9 first pixels
			if (p[pixel[0]] > cb)
				if (p[pixel[1]] > cb)
					if (p[pixel[2]] > cb)
						if (p[pixel[3]] > cb)
							if (p[pixel[4]] > cb)
								if (p[pixel[5]] > cb)
									if (p[pixel[6]] > cb)
										if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb) {
											} else if (p[pixel[15]] > cb) {
											} else
												continue;
										else if (p[pixel[7]] < c_b)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else
													continue;
											else if (p[pixel[14]] < c_b)
												if (p[pixel[8]] < c_b)
													if (p[pixel[9]] < c_b)
														if (p[pixel[10]] < c_b)
															if (p[pixel[11]]
																	< c_b)
																if (p[pixel[12]]
																		< c_b)
																	if (p[pixel[13]]
																			< c_b)
																		if (p[pixel[15]]
																				< c_b) {
																		} else
																			continue;
																	else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else
												continue;
										else
											continue;
									else if (p[pixel[6]] < c_b)
										if (p[pixel[15]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb) {
												} else
													continue;
											else if (p[pixel[13]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																if (p[pixel[11]]
																		< c_b)
																	if (p[pixel[12]]
																			< c_b)
																		if (p[pixel[14]]
																				< c_b) {
																		} else
																			continue;
																	else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																if (p[pixel[13]]
																		< c_b)
																	if (p[pixel[14]]
																			< c_b) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else
												continue;
										else
											continue;
									else if (p[pixel[13]] < c_b)
										if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																if (p[pixel[14]]
																		< c_b)
																	if (p[pixel[15]]
																			< c_b) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[5]] < c_b)
									if (p[pixel[14]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[15]] > cb) {
												} else if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb)
																if (p[pixel[10]]
																		> cb)
																	if (p[pixel[11]]
																			> cb) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[12]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																if (p[pixel[11]]
																		< c_b)
																	if (p[pixel[13]]
																			< c_b) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[14]] < c_b)
										if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																if (p[pixel[13]]
																		< c_b)
																	if (p[pixel[6]]
																			< c_b) {
																	} else if (p[pixel[15]]
																			< c_b) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[6]] < c_b)
										if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b)
																if (p[pixel[13]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																if (p[pixel[11]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[12]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[13]] < c_b)
															if (p[pixel[14]]
																	< c_b)
																if (p[pixel[6]]
																		< c_b) {
																} else if (p[pixel[15]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[4]] < c_b)
								if (p[pixel[13]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb)
																if (p[pixel[10]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb)
																if (p[pixel[10]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[11]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																if (p[pixel[12]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[13]] < c_b)
									if (p[pixel[7]] < c_b)
										if (p[pixel[8]] < c_b)
											if (p[pixel[9]] < c_b)
												if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b)
														if (p[pixel[12]] < c_b)
															if (p[pixel[6]]
																	< c_b)
																if (p[pixel[5]]
																		< c_b) {
																} else if (p[pixel[14]]
																		< c_b) {
																} else
																	continue;
															else if (p[pixel[14]]
																	< c_b)
																if (p[pixel[15]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[5]] < c_b)
									if (p[pixel[6]] < c_b)
										if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b)
												if (p[pixel[9]] < c_b)
													if (p[pixel[10]] < c_b)
														if (p[pixel[11]] < c_b)
															if (p[pixel[12]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[11]] < c_b)
								if (p[pixel[7]] < c_b)
									if (p[pixel[8]] < c_b)
										if (p[pixel[9]] < c_b)
											if (p[pixel[10]] < c_b)
												if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b)
														if (p[pixel[6]] < c_b)
															if (p[pixel[5]]
																	< c_b) {
															} else if (p[pixel[14]]
																	< c_b) {
															} else
																continue;
														else if (p[pixel[14]]
																< c_b)
															if (p[pixel[15]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[3]] < c_b)
							if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb)
															if (p[pixel[9]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[10]] < c_b)
								if (p[pixel[7]] < c_b)
									if (p[pixel[8]] < c_b)
										if (p[pixel[9]] < c_b)
											if (p[pixel[11]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[5]] < c_b)
														if (p[pixel[4]] < c_b) {
														} else if (p[pixel[12]]
																< c_b)
															if (p[pixel[13]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else if (p[pixel[12]] < c_b)
														if (p[pixel[13]] < c_b)
															if (p[pixel[14]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b)
														if (p[pixel[14]] < c_b)
															if (p[pixel[15]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[7]] < c_b)
								if (p[pixel[8]] < c_b)
									if (p[pixel[9]] < c_b)
										if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[5]] < c_b)
														if (p[pixel[4]] < c_b) {
														} else if (p[pixel[13]]
																< c_b) {
														} else
															continue;
													else if (p[pixel[13]] < c_b)
														if (p[pixel[14]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b)
														if (p[pixel[15]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[2]] < c_b)
						if (p[pixel[9]] > cb)
							if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[3]] > cb)
										if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb)
														if (p[pixel[8]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[9]] < c_b)
							if (p[pixel[7]] < c_b)
								if (p[pixel[8]] < c_b)
									if (p[pixel[10]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[4]] < c_b)
													if (p[pixel[3]] < c_b) {
													} else if (p[pixel[11]]
															< c_b)
														if (p[pixel[12]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else if (p[pixel[11]] < c_b)
													if (p[pixel[12]] < c_b)
														if (p[pixel[13]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[11]] < c_b)
												if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b)
														if (p[pixel[14]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b)
														if (p[pixel[15]]
																< c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[9]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[9]] < c_b)
						if (p[pixel[7]] < c_b)
							if (p[pixel[8]] < c_b)
								if (p[pixel[10]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[6]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[4]] < c_b)
													if (p[pixel[3]] < c_b) {
													} else if (p[pixel[12]]
															< c_b) {
													} else
														continue;
												else if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													if (p[pixel[15]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[1]] < c_b)
					if (p[pixel[8]] > cb)
						if (p[pixel[9]] > cb)
							if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[3]] > cb)
										if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[2]] > cb)
									if (p[pixel[3]] > cb)
										if (p[pixel[4]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[7]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[8]] < c_b)
						if (p[pixel[7]] < c_b)
							if (p[pixel[9]] < c_b)
								if (p[pixel[6]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[4]] < c_b)
											if (p[pixel[3]] < c_b)
												if (p[pixel[2]] < c_b) {
												} else if (p[pixel[10]] < c_b)
													if (p[pixel[11]] < c_b) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[10]] < c_b)
												if (p[pixel[11]] < c_b)
													if (p[pixel[12]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[10]] < c_b)
											if (p[pixel[11]] < c_b)
												if (p[pixel[12]] < c_b)
													if (p[pixel[13]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[10]] < c_b)
										if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b)
													if (p[pixel[14]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[10]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b)
													if (p[pixel[15]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[8]] > cb)
					if (p[pixel[9]] > cb)
						if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[2]] > cb)
								if (p[pixel[3]] > cb)
									if (p[pixel[4]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[8]] < c_b)
					if (p[pixel[7]] < c_b)
						if (p[pixel[9]] < c_b)
							if (p[pixel[10]] < c_b)
								if (p[pixel[6]] < c_b)
									if (p[pixel[5]] < c_b)
										if (p[pixel[4]] < c_b)
											if (p[pixel[3]] < c_b)
												if (p[pixel[2]] < c_b) {
												} else if (p[pixel[11]] < c_b) {
												} else
													continue;
											else if (p[pixel[11]] < c_b)
												if (p[pixel[12]] < c_b) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b)
												if (p[pixel[13]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else
					continue;
			else if (p[pixel[0]] < c_b)
				if (p[pixel[1]] > cb)
					if (p[pixel[8]] > cb)
						if (p[pixel[7]] > cb)
							if (p[pixel[9]] > cb)
								if (p[pixel[6]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[4]] > cb)
											if (p[pixel[3]] > cb)
												if (p[pixel[2]] > cb) {
												} else if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[10]] > cb)
												if (p[pixel[11]] > cb)
													if (p[pixel[12]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[10]] > cb)
											if (p[pixel[11]] > cb)
												if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[10]] > cb)
										if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[10]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													if (p[pixel[15]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[8]] < c_b)
						if (p[pixel[9]] < c_b)
							if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[3]] < c_b)
										if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[2]] < c_b)
									if (p[pixel[3]] < c_b)
										if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[1]] < c_b)
					if (p[pixel[2]] > cb)
						if (p[pixel[9]] > cb)
							if (p[pixel[7]] > cb)
								if (p[pixel[8]] > cb)
									if (p[pixel[10]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[4]] > cb)
													if (p[pixel[3]] > cb) {
													} else if (p[pixel[11]]
															> cb)
														if (p[pixel[12]] > cb) {
														} else
															continue;
													else
														continue;
												else if (p[pixel[11]] > cb)
													if (p[pixel[12]] > cb)
														if (p[pixel[13]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[11]] > cb)
												if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb)
														if (p[pixel[14]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb)
														if (p[pixel[15]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[9]] < c_b)
							if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[3]] < c_b)
										if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[2]] < c_b)
						if (p[pixel[3]] > cb)
							if (p[pixel[10]] > cb)
								if (p[pixel[7]] > cb)
									if (p[pixel[8]] > cb)
										if (p[pixel[9]] > cb)
											if (p[pixel[11]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[5]] > cb)
														if (p[pixel[4]] > cb) {
														} else if (p[pixel[12]]
																> cb)
															if (p[pixel[13]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else if (p[pixel[12]] > cb)
														if (p[pixel[13]] > cb)
															if (p[pixel[14]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb)
														if (p[pixel[14]] > cb)
															if (p[pixel[15]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[4]] < c_b)
											if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[3]] < c_b)
							if (p[pixel[4]] > cb)
								if (p[pixel[13]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[12]] > cb)
															if (p[pixel[6]]
																	> cb)
																if (p[pixel[5]]
																		> cb) {
																} else if (p[pixel[14]]
																		> cb) {
																} else
																	continue;
															else if (p[pixel[14]]
																	> cb)
																if (p[pixel[15]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[13]] < c_b)
									if (p[pixel[11]] > cb)
										if (p[pixel[5]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																if (p[pixel[12]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b)
																if (p[pixel[10]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[5]] < c_b)
												if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b)
																if (p[pixel[10]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[5]] > cb)
									if (p[pixel[6]] > cb)
										if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[4]] < c_b)
								if (p[pixel[5]] > cb)
									if (p[pixel[14]] > cb)
										if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb)
																if (p[pixel[13]]
																		> cb)
																	if (p[pixel[6]]
																			> cb) {
																	} else if (p[pixel[15]]
																			> cb) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[14]] < c_b)
										if (p[pixel[12]] > cb)
											if (p[pixel[6]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																if (p[pixel[11]]
																		> cb)
																	if (p[pixel[13]]
																			> cb) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else if (p[pixel[6]] < c_b)
													if (p[pixel[7]] < c_b)
														if (p[pixel[8]] < c_b)
															if (p[pixel[9]]
																	< c_b)
																if (p[pixel[10]]
																		< c_b)
																	if (p[pixel[11]]
																			< c_b) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[6]] > cb)
										if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb)
																if (p[pixel[13]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[5]] < c_b)
									if (p[pixel[6]] > cb)
										if (p[pixel[15]] < c_b)
											if (p[pixel[13]] > cb)
												if (p[pixel[7]] > cb)
													if (p[pixel[8]] > cb)
														if (p[pixel[9]] > cb)
															if (p[pixel[10]]
																	> cb)
																if (p[pixel[11]]
																		> cb)
																	if (p[pixel[12]]
																			> cb)
																		if (p[pixel[14]]
																				> cb) {
																		} else
																			continue;
																	else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[13]] < c_b)
												if (p[pixel[14]] < c_b) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb)
																if (p[pixel[13]]
																		> cb)
																	if (p[pixel[14]]
																			> cb) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[6]] < c_b)
										if (p[pixel[7]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[8]] > cb)
													if (p[pixel[9]] > cb)
														if (p[pixel[10]] > cb)
															if (p[pixel[11]]
																	> cb)
																if (p[pixel[12]]
																		> cb)
																	if (p[pixel[13]]
																			> cb)
																		if (p[pixel[15]]
																				> cb) {
																		} else
																			continue;
																	else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else if (p[pixel[14]] < c_b)
												if (p[pixel[15]] < c_b) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[7]] < c_b)
											if (p[pixel[8]] < c_b) {
											} else if (p[pixel[15]] < c_b) {
											} else
												continue;
										else if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else
												continue;
										else
											continue;
									else if (p[pixel[13]] > cb)
										if (p[pixel[7]] > cb)
											if (p[pixel[8]] > cb)
												if (p[pixel[9]] > cb)
													if (p[pixel[10]] > cb)
														if (p[pixel[11]] > cb)
															if (p[pixel[12]]
																	> cb)
																if (p[pixel[14]]
																		> cb)
																	if (p[pixel[15]]
																			> cb) {
																	} else
																		continue;
																else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[12]] > cb)
									if (p[pixel[7]] > cb)
										if (p[pixel[8]] > cb)
											if (p[pixel[9]] > cb)
												if (p[pixel[10]] > cb)
													if (p[pixel[11]] > cb)
														if (p[pixel[13]] > cb)
															if (p[pixel[14]]
																	> cb)
																if (p[pixel[6]]
																		> cb) {
																} else if (p[pixel[15]]
																		> cb) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b)
																if (p[pixel[11]]
																		< c_b) {
																} else
																	continue;
															else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[11]] > cb)
								if (p[pixel[7]] > cb)
									if (p[pixel[8]] > cb)
										if (p[pixel[9]] > cb)
											if (p[pixel[10]] > cb)
												if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb)
														if (p[pixel[6]] > cb)
															if (p[pixel[5]]
																	> cb) {
															} else if (p[pixel[14]]
																	> cb) {
															} else
																continue;
														else if (p[pixel[14]]
																> cb)
															if (p[pixel[15]]
																	> cb) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b)
															if (p[pixel[10]]
																	< c_b) {
															} else
																continue;
														else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] > cb)
							if (p[pixel[7]] > cb)
								if (p[pixel[8]] > cb)
									if (p[pixel[9]] > cb)
										if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[6]] > cb)
													if (p[pixel[5]] > cb)
														if (p[pixel[4]] > cb) {
														} else if (p[pixel[13]]
																> cb) {
														} else
															continue;
													else if (p[pixel[13]] > cb)
														if (p[pixel[14]] > cb) {
														} else
															continue;
													else
														continue;
												else if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb)
														if (p[pixel[15]] > cb) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b)
														if (p[pixel[9]] < c_b) {
														} else
															continue;
													else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[9]] > cb)
						if (p[pixel[7]] > cb)
							if (p[pixel[8]] > cb)
								if (p[pixel[10]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[6]] > cb)
											if (p[pixel[5]] > cb)
												if (p[pixel[4]] > cb)
													if (p[pixel[3]] > cb) {
													} else if (p[pixel[12]]
															> cb) {
													} else
														continue;
												else if (p[pixel[12]] > cb)
													if (p[pixel[13]] > cb) {
													} else
														continue;
												else
													continue;
											else if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb)
													if (p[pixel[14]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb)
													if (p[pixel[15]] > cb) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else if (p[pixel[9]] < c_b)
						if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b)
													if (p[pixel[8]] < c_b) {
													} else
														continue;
												else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[8]] > cb)
					if (p[pixel[7]] > cb)
						if (p[pixel[9]] > cb)
							if (p[pixel[10]] > cb)
								if (p[pixel[6]] > cb)
									if (p[pixel[5]] > cb)
										if (p[pixel[4]] > cb)
											if (p[pixel[3]] > cb)
												if (p[pixel[2]] > cb) {
												} else if (p[pixel[11]] > cb) {
												} else
													continue;
											else if (p[pixel[11]] > cb)
												if (p[pixel[12]] > cb) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb)
												if (p[pixel[13]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb)
												if (p[pixel[14]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb)
												if (p[pixel[15]] > cb) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else if (p[pixel[8]] < c_b)
					if (p[pixel[9]] < c_b)
						if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b) {
												} else
													continue;
											else
												continue;
										else if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[2]] < c_b)
								if (p[pixel[3]] < c_b)
									if (p[pixel[4]] < c_b)
										if (p[pixel[5]] < c_b)
											if (p[pixel[6]] < c_b)
												if (p[pixel[7]] < c_b) {
												} else
													continue;
											else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else
					continue;
			else if (p[pixel[7]] > cb)
				if (p[pixel[8]] > cb)
					if (p[pixel[9]] > cb)
						if (p[pixel[6]] > cb)
							if (p[pixel[5]] > cb)
								if (p[pixel[4]] > cb)
									if (p[pixel[3]] > cb)
										if (p[pixel[2]] > cb)
											if (p[pixel[1]] > cb) {
											} else if (p[pixel[10]] > cb) {
											} else
												continue;
										else if (p[pixel[10]] > cb)
											if (p[pixel[11]] > cb) {
											} else
												continue;
										else
											continue;
									else if (p[pixel[10]] > cb)
										if (p[pixel[11]] > cb)
											if (p[pixel[12]] > cb) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[10]] > cb)
									if (p[pixel[11]] > cb)
										if (p[pixel[12]] > cb)
											if (p[pixel[13]] > cb) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[10]] > cb)
								if (p[pixel[11]] > cb)
									if (p[pixel[12]] > cb)
										if (p[pixel[13]] > cb)
											if (p[pixel[14]] > cb) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] > cb)
							if (p[pixel[11]] > cb)
								if (p[pixel[12]] > cb)
									if (p[pixel[13]] > cb)
										if (p[pixel[14]] > cb)
											if (p[pixel[15]] > cb) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else
					continue;
			else if (p[pixel[7]] < c_b)
				if (p[pixel[8]] < c_b)
					if (p[pixel[9]] < c_b)
						if (p[pixel[6]] < c_b)
							if (p[pixel[5]] < c_b)
								if (p[pixel[4]] < c_b)
									if (p[pixel[3]] < c_b)
										if (p[pixel[2]] < c_b)
											if (p[pixel[1]] < c_b) {
											} else if (p[pixel[10]] < c_b) {
											} else
												continue;
										else if (p[pixel[10]] < c_b)
											if (p[pixel[11]] < c_b) {
											} else
												continue;
										else
											continue;
									else if (p[pixel[10]] < c_b)
										if (p[pixel[11]] < c_b)
											if (p[pixel[12]] < c_b) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else if (p[pixel[10]] < c_b)
									if (p[pixel[11]] < c_b)
										if (p[pixel[12]] < c_b)
											if (p[pixel[13]] < c_b) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else if (p[pixel[10]] < c_b)
								if (p[pixel[11]] < c_b)
									if (p[pixel[12]] < c_b)
										if (p[pixel[13]] < c_b)
											if (p[pixel[14]] < c_b) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else if (p[pixel[10]] < c_b)
							if (p[pixel[11]] < c_b)
								if (p[pixel[12]] < c_b)
									if (p[pixel[13]] < c_b)
										if (p[pixel[14]] < c_b)
											if (p[pixel[15]] < c_b) {
											} else
												continue;
										else
											continue;
									else
										continue;
								else
									continue;
							else
								continue;
						else
							continue;
					else
						continue;
				else
					continue;
			else
				continue;
			if (num_corners == rsize) {
				rsize *= 2;
				ret_corners = (xy*) realloc(ret_corners, sizeof(xy) * rsize);
			}
			ret_corners[num_corners].x = x;
			ret_corners[num_corners].y = y;
			num_corners++;

		}

	*ret_num_corners = num_corners;
	// Return the potential corners
	return ret_corners;

}

