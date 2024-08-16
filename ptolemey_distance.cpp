// Convert a string to a wide string
std::wstring s2ws(const std::string& s) {
    int slength = static_cast<int>(s.length());
    int len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, nullptr, 0);
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}
 
// Convert a wide string to a string
std::string ws2s(const std::wstring& s) {
    int slength = static_cast<int>(s.length());
    int len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, nullptr, 0, nullptr, nullptr);
    std::string r(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, nullptr, nullptr);
    return r;
}
 
#include <string>
#include <sstream> // Pour std::ostringstream
 
std::string doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
#include <string>
#include <sstream>
#include <iostream>
 
double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double value;
    iss >> value;
    return value;
}
 
 
bool haveip2 = false;
int findip2()
{
    std::string noip(".");
    if (Features::IPSelected.find(noip) != std::string::npos)
    {
        haveip2 = true;
    }
    else {
        haveip2 = false;
    }
    return 0;
}
int findmyip2()
{
    std::string noip(".");
    if (Features::myIPSelected.find(noip) != std::string::npos)
    {
        haveip2 = true;
    }
    else {
        haveip2 = false;
    }
    return 0;
}
 
 
 
bool GeoLocation::findRateLimitedbool = false;
int GeoLocation::findRateLimited()
{
    std::string RateLimited("RateLimited");
    if (GeoLocation::GeoLoc.find(RateLimited) != std::string::npos)
        GeoLocation::findRateLimitedbool = true;
    else {
        GeoLocation::findRateLimitedbool = false;
    }
    return 0;
}
bool GeoLocation::findSignupbool = false;
int GeoLocation::findSignup()
{
    std::string Signup("Sign up");
    if (GeoLocation::GeoLoc.find(Signup) != std::string::npos)
        GeoLocation::findSignupbool = true;
    else {
        GeoLocation::findSignupbool = false;
    }
    return 0;
}
 
bool GeoLocation::findReservedbool = false;
int GeoLocation::findReserved()
{
    std::string Reserved("Reserved IP Address");
    if (GeoLocation::GeoLoc.find(Reserved) != std::string::npos)
        GeoLocation::findReservedbool = true;
    else {
        GeoLocation::findReservedbool = false;
    }
    return 0;
}
 
 
bool GeoLocation::nullboolstringtoint = false;
int GeoLocation::findnull()
{
 
    std::string findnull("null");
    if (GeoLocation::GeoLoc.find(findnull) != std::string::npos)
    {
        GeoLocation::nullboolstringtoint = true;
    }
    else {
        GeoLocation::nullboolstringtoint = false;
    }
    return 0;
}
 
bool GeoLocation::nullboolstringtoint2 = false;
int GeoLocation::findnull2()
{
    std::string findnull("null");
    if (GeoLocation::GeoLoc2.find(findnull) != std::string::npos)
    {
        GeoLocation::nullboolstringtoint2 = true;
    }
    else {
        GeoLocation::nullboolstringtoint2 = false;
    }
    return 0;
}
 
 
 
bool ipapico::myfirstlat = 1;
 
bool ipapico::GeoMain = 0;
 
std::string myipcheck = "";
int ipapico::mainmyGeo() {
 
 
    if (Features::myIPSelected == myipcheck) {
        return 0; // Les IP sont identiques, aucune action supplémentaire nécessaire
    }
    else {
        /*std::string Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
        std::wstring geosUsers = s2ws(Geousers);
        requests2 m_request(L"Mozilla/5.0", false);
        Log::Msg("ipapi log2");
        std::wstring answer = m_request.Get2(false, geosUsers);
        std::string sites = ws2s(answer);*/
        std::string Geousers = "";
        Geousers = "https://ipapi.co/" + Features::myIPSelected + "/json";
        std::wstring geossUsers;
 
        /*std::wstring geosUsers(Geousers.begin(), Geousers.end());*/
        std::wstring geosUsers(s2ws(Geousers));
        geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
        net::requests m_request(ThunderMenu21, false);
        std::wstring answer = m_request.Get2(false, geossUsers);
 
        std::string sites(ws2s(answer));
        Geo::Geosit3s = sites;
        GeoLocation::GeoLoc = Geo::Geosit3s;
        oversee::reserved = "";
        findmyip2();;
        GeoLocation::findRateLimited();
        GeoLocation::findSignup();
        GeoLocation::findReserved();
        GeoLocation::findnull();
        GeoLocation::GeoLoc = "";
 
        if (haveip2)
        {
            if (!GeoLocation::findReservedbool)
            {
                if (!GeoLocation::findRateLimitedbool && !GeoLocation::nullboolstringtoint)
                {
                    if (!GeoLocation::findSignupbool)
                    {
                        auto json = nlohmann::json::parse(answer.begin(), answer.end());
                        if (json.contains("latitude") && json.contains("longitude")) {
                            double latitude = json["latitude"].get<double>();
                            double longitude = json["longitude"].get<double>();
                            oversee::mylatitude = doubleToString(latitude);
                            oversee::mylongitude = doubleToString(longitude);
                            GeoMain = false;
                        }
                        else {
 
                            GeoMain = false;
                        }
                    }
                }
            }
            else
            {
                oversee::reserved = "Reserved IP Address";
            }
        }
        myipcheck = Features::myIPSelected;
 
 
    }
    return 0;
}
 
 
int ipapico::mainGeo() {
    if (Features::IPSelected == Geo::IPCheck) {
        return 0; // Les IP sont identiques, aucune action supplémentaire nécessaire
    }
    else {
        /*std::string Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
        std::wstring geosUsers = s2ws(Geousers);
        requests2 m_request(L"Mozilla/5.0", false);
        Log::Msg("ipapi log9");
        std::wstring answer = m_request.Get2(false, geosUsers);
        std::string sites = ws2s(answer);*/
        std::string Geousers = "";
        Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
        std::wstring geossUsers;
        std::wstring geosUsers(s2ws(Geousers));
        geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
        net::requests m_request(ThunderMenu21, false);
        std::wstring answer = m_request.Get2(false, geossUsers);
        std::string sites(ws2s(answer));
        Geo::Geosit3s = sites;
        GeoLocation::GeoLoc = Geo::Geosit3s;
        oversee::reserved = "";
        findip2();
 
        GeoLocation::findRateLimited();
        GeoLocation::findSignup();
        GeoLocation::findReserved();
        GeoLocation::findnull();
        GeoLocation::GeoLoc = "";
        if (haveip2)
        {
            if (!GeoLocation::findReservedbool)
            {
                if (!GeoLocation::findRateLimitedbool && !GeoLocation::nullboolstringtoint)
                {
                    if (!GeoLocation::findSignupbool)
                    {
                        //try {
                        auto json = nlohmann::json::parse(answer.begin(), answer.end());
                        if (json.contains("city") && json.contains("region") && json.contains("country_name") && json.contains("country_capital") && json.contains("latitude") && json.contains("longitude")) {
                            std::string city = json["city"].get<std::string>();
                            std::string region = json["region"].get<std::string>();
                            std::string country_name = json["country_name"].get<std::string>();
                            std::string country_capital = json["country_capital"].get<std::string>();
                            double latitude = json["latitude"].get<double>();
                            double longitude = json["longitude"].get<double>();
                            oversee::city = city;
                            oversee::region = region;
                            oversee::country_name = country_name;
                            oversee::country_capital = country_capital;
                            oversee::latitude = doubleToString(latitude);
                            oversee::longitude = doubleToString(longitude);
 
                            GeoMain = true;
                        }
                        else {
                            oversee::city = "don't know";
                            oversee::region = "don't know";
                            oversee::country_name = "don't know";
                            oversee::country_capital = "don't know";
                            oversee::latitude = "don't know";
                            oversee::longitude = "don't know";
 
                            GeoMain = false;
                        }
                        /*}
                        catch (const nlohmann::json::parse_error& e) {
                            oversee::city = "don't know";
                            oversee::region = "don't know";
                            oversee::country_name = "don't know";
                            oversee::country_capital = "don't know";
                            oversee::latitude = "don't know";
                            oversee::longitude = "don't know";
 
                            GeoMain = false;
                        }*/
                    }
                }
            }
            else
            {
                oversee::reserved = "Reserved IP Address";
            }
        }
        Geo::IPCheck = Features::IPSelected;
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
static rage::snPlayer* get_session_player(int player)
{
    for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
    {
        if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
        {
            return GetNetwork()->m_game_session_ptr->m_players[i];
        }
 
        if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
            return &GetNetwork()->m_game_session_ptr->m_local_player;
    }
 
    return nullptr;
}
 
static rage::snPeer* get_session_peer(int player)
{
    for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
    {
        if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle.m_rockstar_id == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id)
        {
            return GetNetwork()->m_game_session_ptr->m_peers[i];
        }
    }
    return nullptr;
}
 
static netAddress GetIPAddress(int player)
{
    if ((player == PLAYER::PLAYER_ID()) && (g_GameVariables->m_GetNetPlayer(PLAYER::PLAYER_ID()) != nullptr))
    {
        return g_GameVariables->m_GetNetPlayer(PLAYER::PLAYER_ID())->get_net_data()->m_external_ip;
    }
    if (auto session_player = get_session_player(player))
    {
        if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)get_session_player(player)->m_player_data.m_peer_id_2))
        {
            return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
        }
    }
    return { 0 };
}
 
 
 
 
 
 
 
 
    std::ostringstream ipBuf;
    if (g_GameVariables->m_GetNetPlayer(p) != nullptr)
    {
        auto player_ip = GetIPAddress(p);
        ipBuf << static_cast<int>(player_ip.m_field1) << "." << static_cast<int>(player_ip.m_field2) << "." << static_cast<int>(player_ip.m_field3) << "." << static_cast<int>(player_ip.m_field4);
    }
 
    if (!Features::onlineplayer)
    {
 
        if (Features::GeoLocation)
        {
            Menu::AddSmallTitle02("Geo");
        }
    }
    if (Features::onlineplayer) {
 
 
    Menu::AddSmallInfo((char*)UID.str().c_str(), 18);
    /*Menu::AddSmallInfo(ipBuf, 19);*///notit
    if (g_GameVariables->m_GetNetPlayer(p) != nullptr)
    {
        Menu::AddSmallInfo((char*)ipBuf.str().c_str(), 19);
        /*Features::IPSelected = (char*)ipBuf.str().c_str();
        std::string sIPSelected = "IP: ";
        std::string::size_type i = Features::IPSelected.find(sIPSelected);
        if (i != std::string::npos)
            Features::IPSelected.erase(i, sIPSelected.length());*/
        if (Features::GeoLocation)
        {
            //Geo::IPGeo();
            if (oversee::mylatitude == "" && oversee::mylongitude == "")
            {
                if (ipapico::myfirstlat)
                {
                    playerid();
                    std::ostringstream ipBuf2;
                    if (g_GameVariables->m_GetNetPlayer(Features::playerme) != nullptr)
                    {
                        auto player_ip2 = GetIPAddress(Features::playerme);
                        ipBuf2 << static_cast<int>(player_ip2.m_field1) << "." << static_cast<int>(player_ip2.m_field2) << "." << static_cast<int>(player_ip2.m_field3) << "." << static_cast<int>(player_ip2.m_field4);
                        Features::myIPSelected = (char*)ipBuf2.str().c_str();
                        std::string smyIPSelected = "IP: ";
                        std::string::size_type i = Features::myIPSelected.find(smyIPSelected);
                        if (i != std::string::npos)
                            Features::myIPSelected.erase(i, smyIPSelected.length());
                        ipapico::mainmyGeo();
                        ipapico::myfirstlat = 0;
                    }
 
                }
            }
            Features::IPSelected = (char*)ipBuf.str().c_str();
            std::string sIPSelected = "IP: ";
            std::string::size_type i = Features::IPSelected.find(sIPSelected);
            if (i != std::string::npos)
                Features::IPSelected.erase(i, sIPSelected.length());
 
            ipapico::mainGeo();
            Menu::AddSmallTitle02("Geo");
            if (ipapico::GeoMain)
            {
                if (oversee::reserved != "")
                {
                    char* Geor = new char[oversee::reserved.size() + 1];
                    strcpy(Geor, oversee::reserved.c_str());
                    Menu::AddSmallInfoGeo(Geor, 0);
                }
                else
                {
                    if (oversee::city != "")
                    {
                        char* Geo0 = new char[oversee::city.size() + 1];
                        strcpy(Geo0, oversee::city.c_str());
                        Menu::AddSmallInfoGeo(Geo0, 0);
                    }
                    if (oversee::region != "")
                    {
                        char* Geo01 = new char[oversee::region.size() + 1];
                        strcpy(Geo01, oversee::region.c_str());
                        Menu::AddSmallInfoGeo(Geo01, 1);
                    }
                    if (oversee::country_name != "")
                    {
                        char* Geo02 = new char[oversee::country_name.size() + 1];
                        strcpy(Geo02, oversee::country_name.c_str());
                        Menu::AddSmallInfoGeo(Geo02, 2);
                    }
                    if (oversee::country_capital != "")
                    {
                        char* Geo03 = new char[oversee::country_capital.size() + 1];
                        strcpy(Geo03, oversee::country_capital.c_str());
                        Menu::AddSmallInfoGeo(Geo03, 3);
                    }
                    if (oversee::latitude != "")
                    {
                        std::string lat = "Latitude: " + oversee::latitude;
                        char* Geo04 = new char[lat.size() + 1];
                        strcpy(Geo04, lat.c_str());
                        Menu::AddSmallInfoGeo(Geo04, 4);
                    }
                    if (oversee::longitude != "")
                    {
                        std::string lon = "longitude: " + oversee::longitude;
                        char* Geo05 = new char[lon.size() + 1];
                        strcpy(Geo05, lon.c_str());
                        Menu::AddSmallInfoGeo(Geo05, 5);
                    }
                    if (oversee::latitude != "" && oversee::longitude != "" && oversee::mylatitude != "" && oversee::mylongitude != "")
                    {
                        double latitude1 = std::stod(oversee::latitude);
                        double longitude1 = std::stod(oversee::longitude);
                        double mylatitude2 = std::stod(oversee::mylatitude);
                        double mylongitude2 = std::stod(oversee::mylongitude);
                        double distance = ptolomee::ptolomee_distance(latitude1, longitude1, mylatitude2, mylongitude2);
                        std::ostringstream oss;
                        oss << "distance " << std::fixed << std::setprecision(6) << distance;
                        std::string distanceStr = oss.str();
                        char* charPtr = new char[distanceStr.length() + 1];
                        std::strcpy(charPtr, distanceStr.c_str());
                        Menu::AddSmallInfoGeo(charPtr, 6);
                    }
                    }
                }
            }
        }
    }
}
    std::string Features::myIPSelected;
    std::string Features::IPSelected;
 
 
 
 
 
namespace ipapico
{
    extern bool GeoMain;
    extern int mainGeo();
    extern int mainmyGeo();
    extern bool myfirstlat;
}
 
 
 
#define RADIUS 6371.0 // Rayon de la Terre en km
#define M_PI 3.14159265358979323846
double ptolomee::ptolomee_distance(double lat1, double lon1, double lat2, double lon2) {
// Conversion des coordonnées en radians
double lat1_rad = lat1 * M_PI / 180.0;
double lon1_rad = lon1 * M_PI / 180.0;
double lat2_rad = lat2 * M_PI / 180.0;
double lon2_rad = lon2 * M_PI / 180.0;
// Calcul des différences de longitude et de latitude
double dlon = std::abs(lon2_rad - lon1_rad);
double dlat = std::abs(lat2_rad - lat1_rad);
// Calcul des termes de la formule de Ptolémée
double term1 = std::cos(lat2_rad) * std::sin(dlon);
double term2 = std::cos(lat1_rad) * std::sin(lat2_rad) - std::sin(lat1_rad) * std::cos(lat2_rad) * std::cos(dlon);
double term3 = std::sin(lat1_rad) * std::sin(lat2_rad) + std::cos(lat1_rad) * std::cos(lat2_rad) * std::cos(dlon);
// Calcul de la distance en kilomètres
double distance = RADIUS * std::atan2(std::sqrt(term1 * term1 + term2 * term2), term3);
return distance;
}
