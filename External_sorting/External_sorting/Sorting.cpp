#include "pch.h"
#include "Sorting.h"

// œÓ‚ÂÍ‡ Ì‡ ÓÚÒÓÚËÓ‚‡ÌÌ˚È Ï‡ÒÒË‚
bool Sorting::IsSorted(vc& a)
{
	for (int i = 0; i < a.size() - 1; ++i)
		if (a[i] > a[i + 1]) return false;
	return true;
}

// —ÓÁ‰‡ÌËÂ Ï‡ÒÒË‚Ó‚ 
void Sorting::CreateArray(int Size, vc& A, vc* B, vc* C, vc* D, vc* E)
{
	for (int i = 0; i < Size; ++i) {
		int value = rand() % Size + 1;
		A.push_back(value);
		B->push_back(value);
		C->push_back(value);
		D->push_back(value);
		E->push_back(value);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// —Œ–“»–Œ¬ ¿ œ–Œ—“€Ã ƒ¬”’‘¿«Õ€Ã —À»ﬂÕ»≈Ã
specifications Sorting::ExternalMergeSort2F(vc& a)
{
	specifications s;
	int n = a.size(), sizeB = 0, sizeC = 0;
	vc b(n), c(n);
	unsigned int start_time = clock();
	for (int i = 1; i < n; i *= 2) {
		Separation(b, c, a, n, i, sizeB, sizeC, s.assignments, s.comparisons);
		Merge(b, c, a, n, i, sizeB, sizeC, s.assignments, s.comparisons);
	}
	unsigned int end_time = clock();
	s.time = end_time - start_time;
	return s;
}

// —ÎËˇÌËÂ
void Sorting::Merge(vc& b, vc& c, vc& a, int size, int k, int& sizeB, int& sizeC, int& asig, int& comp)
{
	int indA = 0;
	for (int i = 0; i < size; i += k) {
		int indB = i, indC = i, right = k + i;
		while (indB < min(right, sizeB) && indC < min(right, sizeC)) {
			if (b[indB] < c[indC]) {
				a[indA++] = b[indB++];
				asig++;
			}
			else {
				a[indA++] = c[indC++];
				asig++;
			}
			comp++;
		}
		while (indB < right && indA < size)	{
			a[indA++] = b[indB++];
			asig++;
		}
		while (indC < right && indA < size)	{
			a[indA++] = c[indC++];
			asig++;
		}
	}
}

// –‡Á‰ÂÎÂÌËÂ
void Sorting::Separation(vc& b, vc& c, vc& a, int size, int k, int& sizeB, int& sizeC, int& asig, int& comp)
{
	sizeB = 0;
	sizeC = 0;
	for (int i = 0; i < size; i += k * 2) {
		for (int j = i; j < i + k; j++) {
			if (j < size) {
				b[sizeB++] = a[j];
				asig++;
			}
			if (j + k < size) {
				c[sizeC++] = a[j + k];
				asig++;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// —Œ–“»–Œ¬ ¿ œ–Œ—“€Ã ŒƒÕŒ‘¿«Õ€Ã —À»ﬂÕ»≈Ã
specifications Sorting::ExternalMergeSort1F(vc& a)
{
	specifications s;
	int n = a.size(), flag = 0, temp = 1, sizeB = 0, sizeC = 0;
	vc  b(n), c(n), d(n), e(n);

	unsigned int start_time = clock();
	FirstSeparation(a, b, c, n, s.assignments, s.comparisons, sizeB, sizeC); // Ì‡˜‡Î¸ÌÓÂ ‡Á‰ÂÎÂÌËÂ
	for (; temp <= n / 2; temp *= 2) {
		if (flag++ % 2 == 0)
			Separation(b, c, d, e, temp, n, s.assignments, s.comparisons, sizeB, sizeC);
		else
			Separation(d, e, b, c, temp, n, s.assignments, s.comparisons, sizeB, sizeC);
	}
	if (flag % 2 != 0)
		FinalMerge(d, e, a, n, s.assignments, s.comparisons, sizeB, sizeC); // ÍÓÌÂ˜ÌÓÂ ÒÎËˇÌËÂ
	else
		FinalMerge(b, c, a, n, s.assignments, s.comparisons, sizeB, sizeC);
	unsigned int end_time = clock();
	s.time = end_time - start_time;

	return s;
}

// ‘ËÌ‡Î¸ÌÓÂ ÒÎËˇÌËÂ
void Sorting::FinalMerge(vc& b, vc& c, vc& a, int size, int& asig, int& comp, int& sizeD, int& sizeE)
{
	int indA = 0, indB = 0, indC = 0;
	while (indB < sizeD && indC < sizeE) {
		if (b[indB] < c[indC]) {
			a[indA++] = b[indB++];
			asig++;
		}
		else {
			a[indA++] = c[indC++];
			asig++;
		}
		comp++;
	}
	while (indC < sizeE) {
		a[indA++] = c[indC++];
		asig++;
	}
	while (indB < sizeD){
		a[indA++] = b[indB++];
		asig++;
	}
}

// —ÎËˇÌËÂ ‚ 1 Ù‡ÈÎ
void Merge1f(vc& b, vc& c, vc&d, int& indB, int& indC, int& indD, int r, int& sizeC, int& sizeB, int& asig, int& comp)
{
	while (indC < min(r, sizeC) && indB < min(r, sizeB)) {
		if (b[indB] > c[indC]) {
			d[indD++] = c[indC++];
			asig++;
		}
		else {
			d[indD++] = b[indB++];
			asig++;
		}
		comp++;
	}
	while (indC < min(r, sizeC)) {
		d[indD++] = c[indC++];
		asig++;
	}
	while (indB < min(r, sizeB)) {
		d[indD++] = b[indB++];
		asig++;
	}
}

// –‡Á‰ÂÎÂÌËÂ Ë ÒÎËˇÌËÂ ‚ ‰‚‡ Ù‡ÈÎ‡
void Sorting::Separation(vc& b, vc& c, vc& d, vc& e, int k, int n, int& asig, int& comp, int &sizeD, int& sizeE)
{
	int indD = 0, indE = 0, indB = 0, indC = 0;
	for (int i = 0; i < n; i += k * 2) {
		Merge1f(b, c, d, indB, indC, indD, i + k, sizeE, sizeD, asig, comp);
		Merge1f(b, c, e, indB, indC, indE, i + 2 * k, sizeE, sizeD, asig, comp);
	}
	sizeD = indD;
	sizeE = indE;

}

// œÂ‚ÓÂ ‡Á‰ÂÎÂÌËÂ
void Sorting::FirstSeparation(vc& a, vc& b, vc& c, int n, int& asig, int& comp, int&sizeB, int&sizeC)
{
	int indB = 0, indC = 0;
	for (int i = 0; i < n; i += 2) {
		b[indB++] = a[i];
		asig++;
		if (i + 1 < n) {
			c[indC++] = a[i + 1];
			asig++;
		}
	}
	sizeB = indB;
	sizeC = indC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// ƒ¬”’‘¿«Õ¿ﬂ —Œ–“»–Œ¬ ¿ ≈—“≈—“¬≈ÕÕ€Ã —À»ﬂÕ»≈Ã
specifications Sorting::ExternalNaturalMergingSort1f(vc& a)
{
	specifications s;
	int sizeB = 1, sizeC = 1, n = a.size();
	vc b(n), c(n);
	unsigned int start_time = clock();
	while (sizeB > 0 && sizeC > 0) {
		SeparationNM1f(b, c, a, n, sizeB, sizeC, s.assignments, s.comparisons);
		MergeNM1f(b, c, a, n, sizeB, sizeC, s.assignments, s.comparisons);
	}
	unsigned int end_time = clock();
	s.time = end_time - start_time;
	return s;
}

void Sorting::MergeNM1f(vc& b, vc& c, vc& a, int size, int& sizeB, int& sizeC, int& asig, int& comp)
{
	int indA = 0, indC = 0, indB = 0;
	while (indA < size) {
		while (indB < sizeB - 1 && b[indB] <= b[indB + 1] && indC < sizeC - 1 && c[indC] <= c[indC + 1]) {
			if (b[indB] < c[indC]) {
				a[indA++] = b[indB++];
				asig++;
			}
			else {
				a[indA++] = c[indC++];
				asig++;
			}
			comp+= 3;
		}
		if (indC < sizeC - 1 && c[indC] > c[indC + 1] || indC == sizeC - 1) {
			while (indB < sizeB - 1 && b[indB] <= b[indB + 1]) {
				if (c[indC] > b[indB]) {
					a[indA++] = b[indB++];
					asig++;
				} else {
					a[indA++] = c[indC];
					asig++;
					c[indC] = null;
				}
				comp++;
			}
			if (c[indC] != null){
				a[indA++] = c[indC++];
				asig++;
			}
			else
				indC++;
			if (indB < sizeB) {
				a[indA++] = b[indB++];
				asig++;
			}
		}
		else if (indB< sizeB - 1 && b[indB] > b[indB + 1] || indB == sizeB - 1) {
			while (indC < sizeC - 1 && c[indC] <= c[indC + 1]) {
				if (c[indC] > b[indB]) {
					a[indA++] = b[indB];
					b[indB] = null;
					asig++;
				}
				else {
					a[indA++] = c[indC++];
					asig++;
				}
				comp++;
			}
			if (b[indB] != null) {
				a[indA++] = b[indB++];
				asig++;
			}
			else
				indB++;
			if (indC < sizeC) {
				a[indA++] = c[indC++];
				asig++;
			}
		}
		else if (sizeC == indC)
			while (indB < sizeB) {
				a[indA++] = b[indB++];
				asig++;
			}
		else if (sizeB == indB)
			while (indC < sizeC) {
				a[indA++] = c[indC++];
				asig++;
			}
	}
}

void Sorting::SeparationNM1f(vc& b, vc& c, vc& a, int size, int& sizeB, int& sizeC, int& asig, int& comp)
{
	int ind = 0, indB = 0, indC = 0;
	while (ind < size) {
		while (ind < size - 1 && a[ind] <= a[ind + 1]) {
			b[indB++] = a[ind++];
			asig++;
			comp++;
		}
		if (ind >= size) break;
		b[indB++] = a[ind++];
		asig++;
		while (ind < size - 1 && a[ind] <= a[ind + 1]) {
			c[indC++] = a[ind++];
			asig++;
			comp++;
		}
		if (ind >= size) break;
		c[indC++] = a[ind++];
		asig++;
	}
	sizeB = indB;
	sizeC = indC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// ŒƒÕŒ‘¿«Õ¿ﬂ —Œ–“»–Œ¬ ¿ ≈—“≈—“¬≈ÕÕ€Ã —À»ﬂÕ»≈Ã
specifications Sorting::ExternalNaturalMergingSort2f(vc& a)
{
	specifications s;
	int sizeB = -1, sizeC = -1, sizeE = -1, sizeD = -1, n = a.size();
	vc b(n), c(n), e(n), d(n);
	int flag = 0;
	unsigned int start_time = clock();
	SeparationNM1f(b, c, a, n, sizeB, sizeC, s.assignments, s.comparisons);
	while (sizeB != 0 && sizeC != 0 && sizeE != 0 && sizeD != 0) {
		if (flag % 2 == 0)
			MergeNM2f(b, c, e, d, n, sizeB, sizeC, sizeE, sizeD, s.assignments, s.comparisons);
		else
			MergeNM2f(e, d, b, c, n, sizeE, sizeD, sizeB, sizeC, s.assignments, s.comparisons);
		flag++;
	}
	if (sizeB == n) a = b;
	else if (sizeC == n) a = c;
	else if (sizeE == n) a = e;
	else a = d;
	unsigned int end_time = clock();
	s.time = end_time - start_time;
	return s;
}

void Sorting::MergeNM2f(vc& b, vc& c, vc& e, vc& d, int size, int& sizeB, int& sizeC, int& sizeE, int& sizeD, int& asig, int& comp)
{
	int indE = 0, indD = 0, indC = 0, indB = 0;
	while (indE + indD < size) {
		MergeNM(b, c, e, sizeB, sizeC, indE, indB, indC, asig, comp);
		MergeNM(b, c, d, sizeB, sizeC, indD, indB, indC, asig, comp);
	}
	sizeE = indE;
	sizeD = indD;
}

void Sorting::MergeNM(vc& b, vc& c, vc& e, int& sizeB, int& sizeC, int& indE, int& indB, int& indC, int& asig, int& comp)
{
	while (indB < sizeB - 1 && b[indB] <= b[indB + 1] && indC < sizeC - 1 && c[indC] <= c[indC + 1]) {
		if (b[indB] < c[indC])
			e[indE++] = b[indB++];
		else
			e[indE++] = c[indC++];
		comp++;
		asig++;
	}
	if (indC < sizeC - 1 && c[indC] > c[indC + 1] || indC == sizeC - 1) {
		while (indB < sizeB - 1 && b[indB] <= b[indB + 1]) {
			if (c[indC] > b[indB])
				e[indE++] = b[indB++];
			else
			{
				e[indE++] = c[indC];
				c[indC] = null;
			}
			comp++;
			asig++;
		}
		if (c[indC] != null) {
			e[indE++] = c[indC++];
			asig++;
		}
		else
			indC++;
		if (indB < sizeB) {
			e[indE++] = b[indB++];
			asig++;
		}
	}
	else if (indB< sizeB - 1 && b[indB] > b[indB + 1] || indB == sizeB - 1) {
		while (indC < sizeC - 1 && c[indC] <= c[indC + 1]) {
			if (c[indC] > b[indB]) {
				e[indE++] = b[indB];
				b[indB] = null;
			}
			else
				e[indE++] = c[indC++];
			asig++;
			comp++;
		}
		if (b[indB] != null) {
			e[indE++] = b[indB++];
			asig++;
		}
		else
			indB++;
		if (indC < sizeC) {
			e[indE++] = c[indC++];
			asig++;
		}
	}
	else if (sizeC == indC)
		while (indB < sizeB) {
			e[indE++] = b[indB++];
			asig++;
		}
	else if (sizeB == indB)
		while (indC < sizeC) {
			e[indE++] = c[indC++];
			asig++;
		}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
// —Œ–“»–Œ¬ ¿ œŒ√ÀŒŸ≈Õ»≈Ã
specifications Sorting::AbsorbingSort(vc& a)
{
	specifications s;
	int n = a.size()-1;
	vc b(n);
	int op = a[n];
	unsigned int start_time = clock();
	for (int i = 1; n - (i - 1) * op >= 0; i++)
		Absorging(a, b,n - i * op, n - (i - 1) * op, op, n, s.assignments, s.comparisons);
	unsigned int end_time = clock();
	s.time = end_time - start_time;
	a.pop_back();
	return s;
}

void Sorting::Absorging(vc& a, vc& b, int l, int r, int op, int size, int& asig, int& comp)
{
	int indB = 0;
	for (int i = max(l, 0); i < r; ++i)
		b[indB++] = a[i];
	int sizeB = indB;
	indB = 0;
	sort(b.begin(), b.begin() + sizeB);
	int inda = max(0, l);
	int indA = max(l + op, 0);
	while (indA < size && indB < sizeB) {
		if (a[indA] < b[indB])
			a[inda++] = a[indA++];
		else
			a[inda++] = b[indB++];
		asig++;
		comp++;
	}
	while (indB < sizeB) {
		a[inda++] = b[indB++];
		asig++;
	}
	while (inda < size && indA < size) {
		a[inda++] = a[indA++];
		asig++;
	}
}
