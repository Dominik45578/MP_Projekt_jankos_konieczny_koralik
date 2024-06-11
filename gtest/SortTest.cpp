#include "pch.h"
#include "../sortingalg.cpp"
#include "../BubbleSort.cpp"
#include "../QuickSort.cpp"
#include "../MergeSort.cpp"
#include "../HeapSort.cpp"
#include <vector>
#include <ctime>
#include <algorithm>

int losujIloscDanych() {
	srand(time(0));
	return rand() % 1000 + 10;
}

bool porownaj(const std::vector<int> jeden, const std::vector<int> dwa) {
	for (int i = 0; i < jeden.size(); i++) {
		if (jeden[i] != dwa[i])
			return false;

		return true;
	}
}

void generujLiczby(std::vector<int>& data, const int iloscDanych = 10) {
	srand(time(0));
	for (int i = 0; i < iloscDanych; i++) {
		data.push_back(rand() % 10 + 1);
	}
}

// -------------- LOSOWE DANE --------------

TEST(LosoweDane, MergeSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	std::vector<int> probaKontrolna = data;
	sort(probaKontrolna.begin(), probaKontrolna.end());

	SortingAlg* alg = new MergeSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(LosoweDane, HeapSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	std::vector<int> probaKontrolna = data;
	sort(probaKontrolna.begin(), probaKontrolna.end());

	SortingAlg* alg = new HeapSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(LosoweDane, QuickSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	std::vector<int> probaKontrolna = data;
	sort(probaKontrolna.begin(), probaKontrolna.end());

	SortingAlg* alg = new QuickSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(LosoweDane, BubbleSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	std::vector<int> probaKontrolna = data;
	sort(probaKontrolna.begin(), probaKontrolna.end());

	SortingAlg* alg = new BubbleSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

// -------------- PUSTA --------------
TEST(Pusta, MergeSort) {
	std::vector<int> data;
	SortingAlg* alg = new MergeSort(data);

	ASSERT_NO_THROW(alg->sort());
	ASSERT_TRUE(alg->getData().empty());
}

TEST(Pusta, QuickSort) {
	std::vector<int> data;
	SortingAlg* alg = new QuickSort(data);

	ASSERT_NO_THROW(alg->sort());
	ASSERT_TRUE(alg->getData().empty());
}

TEST(Pusta, BubbleSort) {
	std::vector<int> data;
	SortingAlg* alg = new BubbleSort(data);

	ASSERT_NO_THROW(alg->sort());
	ASSERT_TRUE(alg->getData().empty());
}

TEST(Pusta, HeapSort) {
	std::vector<int> data;
	SortingAlg* alg = new HeapSort(data);

	ASSERT_NO_THROW(alg->sort());
	ASSERT_TRUE(alg->getData().empty());
}

// -------------- POSORTOWANA --------------

TEST(Posortowana, MergeSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	SortingAlg* alg = new MergeSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), data));
}

TEST(Posortowana, HeapSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	SortingAlg* alg = new HeapSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), data));
}

TEST(Posortowana, QuickSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	SortingAlg* alg = new QuickSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), data));
}

TEST(Posortowana, BubbleSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	SortingAlg* alg = new BubbleSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), data));
}

// -------------- POSORTOWANA ODWROTNIE --------------

TEST(PosortowanaOdwrotnie, MergeSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	std::vector<int> probaKontrolna = data;
	reverse(data.begin(), data.end());

	SortingAlg* alg = new MergeSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(PosortowanaOdwrotnie, HeapSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	std::vector<int> probaKontrolna = data;
	reverse(data.begin(), data.end());

	SortingAlg* alg = new HeapSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(PosortowanaOdwrotnie, QuickSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	std::vector<int> probaKontrolna = data;
	reverse(data.begin(), data.end());

	SortingAlg* alg = new QuickSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}

TEST(PosortowanaOdwrotnie, BubbleSort) {
	std::vector<int> data;
	generujLiczby(data, losujIloscDanych());

	sort(data.begin(), data.end());

	std::vector<int> probaKontrolna = data;
	reverse(data.begin(), data.end());


	SortingAlg* alg = new BubbleSort(data);
	alg->sort();

	ASSERT_TRUE(porownaj(alg->getData(), probaKontrolna));
}