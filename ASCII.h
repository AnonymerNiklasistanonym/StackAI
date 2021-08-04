#pragma once
#include "Randomizer.h"
namespace ASCII {
	static const int empty = 0;
	static const int face = 1;
	static const int face2 = 2;
	static const int heart = 3;
	static const int diamond = 4;
	static const int club = 5;
	static const int spades = 6;
	static const int point = 7;
	static const int point_inv = 8;
	static const int circle = 9;
	static const int circle_inv = 10;
	static const int male = 11;
	static const int female = 12;
	static const int note = 13;
	static const int notes = 14;
	static const int sun = 15;
	static const int arrow_thick_r = 16;
	static const int arrow_thick_l = 17;
	static const int arrow_thick_up_down = 18;
	static const int double_bang = 19;
	static const int paragraph = 20;
	static const int law = 21;
	static const int underscore_thick = 22;
	static const int arrow_up_down = 23;
	static const int arrow_up = 24;
	static const int arrow_down = 25;
	static const int arrow_right = 26;
	static const int arrow_left = 27;
	static const int uptick_line = 28;
	static const int arrow_left_right = 29;
	static const int arrow_thick_up = 30;
	static const int arrow_thick_down = 31;
	static const int empty2 = 32;
	static const int bang = 33;
	static const int quotation_mark = 34;
	static const int hash = 35;
	static const int dollar = 36;
	static const int percent = 37;
	static const int ampersand = 38;
	static const int apostrophe = 39;
	static const int parenthesis_open = 40;
	static const int parenthesis_closed = 41;
	static const int asterisk = 42;
	static const int plus = 43;
	static const int comma = 44;
	static const int hyphen = 45;
	static const int dot = 46;
	static const int slash_fwd = 47;
	static const int n0 = 48;
	static const int n1 = 49;
	static const int n2 = 50;
	static const int n3 = 51;
	static const int n4 = 52;
	static const int n5 = 53;
	static const int n6 = 54;
	static const int n7 = 55;
	static const int n8 = 56;
	static const int n9 = 57;
	static const int colon = 58;
	static const int semicolon = 59;
	static const int smaller_then = 60;
	static const int equals = 61;
	static const int bigger_then = 62;
	static const int questionmark = 63;
	static const int at = 64;
	static const int A = 65;
	static const int B = 66;
	static const int C = 67;
	static const int D = 68;
	static const int E = 69;
	static const int F = 70;
	static const int G = 71;
	static const int H = 72;
	static const int I = 73;
	static const int J = 74;
	static const int K = 75;
	static const int L = 76;
	static const int M = 77;
	static const int N = 78;
	static const int O = 79;
	static const int P = 80;
	static const int Q = 81;
	static const int R = 82;
	static const int S = 83;
	static const int T = 84;
	static const int U = 85;
	static const int V = 86;
	static const int W = 87;
	static const int X = 88;
	static const int Y = 89;
	static const int Z = 90;
	static const int bracket_open = 91;
	static const int bwd_slash = 92;
	static const int bracket_close = 93;
	static const int sqr = 94;
	static const int underscore = 95;
	static const int bwd_apostrophe = 96;
	static const int a = 97;
	static const int b = 98;
	static const int c = 99;
	static const int d = 100;
	static const int e = 101;
	static const int f = 102;
	static const int g = 103;
	static const int h = 104;
	static const int i = 105;
	static const int j = 106;
	static const int k = 107;
	static const int l = 108;
	static const int m = 109;
	static const int n = 110;
	static const int o = 111;
	static const int p = 112;
	static const int q = 113;
	static const int r = 114;
	static const int s = 115;
	static const int t = 116;
	static const int u = 117;
	static const int v = 118;
	static const int w = 119;
	static const int x = 120;
	static const int y = 121;
	static const int z = 122;
	static const int curved_bracket_open = 123;
	static const int line = 124;
	static const int curved_bracket_close = 125;
	static const int tilde = 126;
	static const int roof = 127;

	static const int dither_min = 176;
	static const int dither_med = 177;
	static const int dither_max = 178;
	static const int wall_ns = 179;
	static const int wall_nsw = 180;
	static const int wall_nsW = 181;
	static const int wall_NSw = 182;
	static const int wall_Sw = 183;
	static const int wall_sW = 184;
	static const int wall_NSW = 185;
	static const int wall_NS = 186;
	static const int wall_SW = 187;
	static const int wall_NW = 188;
	static const int wall_Nw = 189;
	static const int wall_nW = 190;
	static const int wall_sw = 191;
	static const int wall_ne = 192;
	static const int wall_new = 193;
	static const int wall_esw = 194;
	static const int wall_nes = 195;
	static const int wall_ew = 196;
	static const int wall_nesw = 197;
	static const int wall_nEs = 198;
	static const int wall_NeS = 199;
	static const int wall_NE = 200;
	static const int wall_ES = 201;
	static const int wall_NEW = 202;
	static const int wall_ESW = 203;
	static const int wall_NES = 204;
	static const int wall_EW = 205;
	static const int wall_NESW = 206;
	static const int wall_nEW = 207;
	static const int wall_New = 208;
	static const int wall_EsW = 209;
	static const int wall_eSw = 210;
	static const int wall_Ne = 211;
	static const int wall_bE = 212;
	static const int wall_Es = 213;
	static const int wall_eS = 214;
	static const int wall_NeSw = 215;
	static const int wall_nEsW = 216;
	static const int wall_nw = 217;
	static const int wall_es = 218;
	static const int block_full = 219;
	static const int block_half_bottom = 220;
	static const int block_half_left = 221;
	static const int block_half_right = 222;
	static const int block_half_up = 223;
	static const int filled = 255;


	static int get_random_ground() {
		switch (random_custom::getInt(20)) {
		case 0:
			return dot;
		case 1:
			return comma;
		case 2:
			return hyphen;
		case 3:
			return apostrophe;
		case 4:
			return bwd_apostrophe;
		}
		return empty;
	}
}
