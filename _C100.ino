//#######################################################################################################
//########################### Controller Plugin 100: KNX-IP [DEVELOPMENT] #######################################
//#######################################################################################################

#ifdef PLUGIN_BUILD_DEV

#define CPLUGIN_100
#define CPLUGIN_ID_100         100
#define CPLUGIN_NAME_100       "KNX-IP [DEVELOPMENT]"

struct C100_ConfigStruct
{
  boolean dummy;
  byte area_
};

boolean CPlugin_100(byte function, struct EventStruct *event, String& string)
{
  boolean success = false;

  switch (function)
  {
    case CPLUGIN_PROTOCOL_ADD:
      {
        Protocol[++protocolCount].Number = CPLUGIN_ID_100;
        Protocol[protocolCount].usesMQTT = false;
        Protocol[protocolCount].usesAccount = false;
        Protocol[protocolCount].usesPassword = false;
        Protocol[protocolCount].defaultPort = 80;
        break;
      }

    case CPLUGIN_GET_DEVICENAME:
      {
        string = F(CPLUGIN_NAME_100);
        break;
      }

    case CPLUGIN_WEBFORM_LOAD:
      {
        break;
      }

    case CPLUGIN_WEBFORM_SAVE:
      {
        break;
      }

    case CPLUGIN_PROTOCOL_SEND:
      {
        switch (event->sensorType)
        {
          case SENSOR_TYPE_SINGLE:                      // single value sensor, used for Dallas, BH1750, etc
          case SENSOR_TYPE_SWITCH:
          case SENSOR_TYPE_DIMMER:
            break;
          case SENSOR_TYPE_LONG:                      // single LONG value, stored in two floats (rfid tags)

            break;
          case SENSOR_TYPE_TEMP_HUM:
          case SENSOR_TYPE_TEMP_BARO:
            {

              break;
            }
          case SENSOR_TYPE_TEMP_HUM_BARO:
            {
              break;
            }
        }
        break;
      }

  }
  return success;
}

#endif /* of PLUGIN_BUILD_DEV */