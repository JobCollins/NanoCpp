#pragma once

//old enum
enum Status
{
	Pending,
	Approved,
	Cancelled
};

//new enum; scoped enum
enum class FileError
{
	notfound,
	ok
};

enum class NetworkError
{
	disconnected,
	ok
};
