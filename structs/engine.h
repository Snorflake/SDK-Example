class CEngine
{
public:

	void GetScreenSize( int& Width, int& Height )
	{
		typedef void( __thiscall* Fn )(void*, int&, int&);
		return ((Fn)VMT.GetFunction(this, indexes::GetScreenSize))(this, Width, Height);
	}

	bool GetPlayerInfo( int Index, player_info_t* PlayerInfo )
	{
		typedef bool(__thiscall* Fn)(void*, int, player_info_t*);
		return ((Fn)VMT.GetFunction(this, indexes::GetPlayerInfo))(this, Index, PlayerInfo);
	}

	int GetLocalPlayer()
	{
		typedef int(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, indexes::GetLocalPlayer))(this);
	}

	void ClientCmd( const char* Command )
	{
		typedef void(__thiscall* Fn)(void*, const char*);
		return ((Fn)VMT.GetFunction(this, indexes::ClientCmd))(this, Command);
	}

	void SetViewAngles( Vector& Angles )
	{
		typedef void(__thiscall* Fn)(void*, Vector&);
		return ((Fn)VMT.GetFunction(this, indexes::SetViewAngles))(this, Angles);
	}

	void GetViewAngles(Vector& angle)
	{
		typedef void(__thiscall* Fn)(void*, Vector&);
		return ((Fn)VMT.GetFunction(this, indexes::GetViewAngles))(this,angle);
	}

	VMatrix& WorldToScreenMatrix()
	{
		typedef VMatrix& (__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, indexes::WorldToScreenMatrix))(this);
	
	}

};