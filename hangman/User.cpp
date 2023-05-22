// Wt
#include <Wt/Auth/Dbo/AuthInfo.h>
#include <Wt/Dbo/Impl.h>

// local
#include "User.hpp"

DBO_INSTANTIATE_TEMPLATES(User);

using namespace Wt::Dbo;
User::User() : gamesPlayed(0), score(0) {}