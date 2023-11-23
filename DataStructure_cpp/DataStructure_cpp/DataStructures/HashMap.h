#pragma once

#include <iostream>
#include <vector>

#define HASH_TABLE_SIZE 500

template<typename KeyType, typename ValueType>
class HashMap
{
private:
	struct Bucket
	{
	public:
		Bucket(const KeyType& key, const ValueType& value)
			:key(key), value(value), next(nullptr)
		{}

		KeyType key;
		ValueType value;
		Bucket* next;
	};

public:
	HashMap()
	{
		buckets.resize(HASH_TABLE_SIZE, nullptr);
	}
	~HashMap()
	{
		for (auto iter = 0; iter < HASH_TABLE_SIZE; iter++)
		{
			if (buckets[iter] != nullptr)
				delete buckets[iter];
		}

		buckets.clear();
	}

	void Insert(const KeyType& key, const ValueType& value)
	{
		int hash = GetHash(key);
		if (!buckets[hash])
		{
			buckets[hash] = new Bucket(key, value);
			return;
		}

		//충돌이 발생한 경우
		Bucket* bucket = buckets[hash];
		while (bucket->next != nullptr)
		{
			if (bucket->key == key)
			{
				//이미 등록이 된 경우
				bucket->value = value;
				return;
			}

			bucket = bucket->next;
		}

		bucket->next = new Bucket(key, value);
	}

	ValueType& Find(const KeyType& key)
	{
		int hash = GetHash(key);
		if (buckets[hash] == nullptr)
			return NULL;

		Bucket* bucket = buckets[hash];

		while (bucket != nullptr)
		{
			if (bucket->key == key)
				return bucket->value;

			bucket = bucket->next;
		}

		return NULL;
	}

	void Remove(const KeyType& key)
	{
		int hash = GetHash(key);
		if (buckets[hash] == nullptr)
			return;

		Bucket* bucket = buckets[hash];
		Bucket* prevBucket = nullptr;
		while (bucket != nullptr)
		{
			if (bucket->key == key)
			{
				if (prevBucket)
					prevBucket->next = nullptr;
				else
					buckets[hash] = bucket->next;

				delete bucket;
				return;
			}

			prevBucket = bucket;
			bucket = bucket->next;
		}

		return;
	}

private:
	inline int GetHash(const KeyType& key)
	{
		int prime = 31;
		int sum = 0;
		for (int i = 0; key[i]; i++)
			sum = (sum * prime + static_cast<int>(key[i])) % HASH_TABLE_SIZE;

		return sum;
	}

private:
	std::vector<Bucket*> buckets;
};