// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================

// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010, maxe = maxn * 40;

int n, m, u, v, l, r, k, t, tn, pos, mid, ans, now, lastans;
int val[maxn], tmp[maxn], root[maxn], dep[maxn];
int f[maxn][20];
int sum[maxe], lc[maxe], rc[maxe];

int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
}

void build(int &u, int l = 1, int r = tn) {
	u = ++pos;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &u, int v, int k, int l = 1, int r = tn) {
	u = ++pos;
	lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], lc[v], k, l, mid);
	else modify(rc[u], rc[v], k, mid + 1, r);
}

int query(int a, int b, int c, int d, int k, int l = 1, int r = tn) {
	if (l == r) return l;
	int now = sum[lc[a]] + sum[lc[b]] - sum[lc[c]] - sum[lc[d]];
	int mid = (l + r) >> 1;
	if (k <= now) return query(lc[a], lc[b], lc[c], lc[d], k, l, mid);
	else return query(rc[a], rc[b], rc[c], rc[d], k - now, mid + 1, r);
}

void dfs(int u) {
	modify(root[u], root[f[u][0]], val[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0])  {
			f[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		 std::swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] ^ f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(val[i]);
		tmp[i] = val[i];
	}
	std::sort(tmp + 1, tmp + n + 1);
	tn = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++)
		val[i] = std::lower_bound(tmp + 1, tmp + tn + 1, val[i]) - tmp;
//	for (int i = 1; i <= n; i++)
//		print(val[i], ' ');
//	putc('\n');
//	for (int i = 1; i <= tn; i++)
//		print(tmp[i], ' ');
//	putc('\n');
		
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		add_edge(u, v);
		add_edge(v, u);
	}
	
	build(root[0]);
	dep[1] = 1, dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(k);
		t = lca(u, v);
		print(lastans = tmp[query(root[u], root[v], root[t], root[f[t][0]], k)]);
	}

	return 0;
}
