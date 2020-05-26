--- All OA gateway constants are defined here
-- @module const
-- @author        Potulski Dirk , Garge Shekhar, Sangeeth Kumar

_VER = "1.2.0"


PROTOCOL_JSON = "json"

DATETIME_PATTERN = "%Y-%m-%dT%H:%M:%S"

LOG_DEBUG   = "debug"
LOG_INFO    = "info"
LOG_WARNING = "warning"
LOG_ERROR   = "error"
LOG_VERBOSE = "verbose"


LUATYPE_STRING  = "string"
LUATYPE_NUMBER  = "number"
LUATYPE_TABLE   = "table"
LUATYPE_BOOLEAN = "boolean"

JSONTYPE_OBJECT   = "object"

-- Database id's

OA_SYSTEM_DATA   = "OA_SYSTEM_DATA"
OA_CLIENT_DATA   = "OA_CLIENT_DATA"
DOM_UI_DATA      = "DOM_UI_DATA"
DOM_CONTENT_DATA = "DOM_CONTENT_DATA"

DB_FILES =
{
    OA_SYSTEM_DATA   = "oa-system-data.db"
  , OA_CLIENT_DATA   = "oa-client-data.db"
  , DOM_UI_DATA      = "dom-ui-data.db"
  , DOM_CONTENT_DATA = "dom-content-data.db"
}

--lua version specific to database
LUA_DATABASE_CONSTANTS =
{
    OA_SYSTEM_DATA   = "1.0.0"
  , OA_CLIENT_DATA   = "1.0.0"
  , DOM_UI_DATA      = "1.0.0"
  , DOM_CONTENT_DATA = "1.0.0"
}

--version incompatible errors
INFOTXT_DATABASE_VERSION_MISMATCH = "Lua version is incompatible with the database version (%s)"
INFOTXT_DOWNLOADED_DATABASE_VERSION_MISMATCH = "Downloaded database is incompatible with installed database version (%s)"

-- System parameter constants

SYSPARAM_DB_VERSION              = "DB_VERSION"
SYSPARAM_URL_DOM_CONTENT_SERVICE = "URL_DOM_CONTENT_SERVICE"

-- Client data value groups

CLIENT_VALUE_GROUP_MESSAGE   = "MESSAGE"
CLIENT_VALUE_GROUP_BOOKMARK  = "BOOKMARK"
CLIENT_VALUE_GROUP_STATISTIC = "STATISTIC"
CLIENT_VALUE_GROUP_SETTING   = "SETTING"
CLIENT_VALUE_GROUP_SESSION   = "SESSION"

-- Response info texts

INFOTYPE_INFO   = 1
INFOTYPE_WARN   = 2
INFOTYPE_BUSERR = 3
INFOTYPE_SYSERR = 4

---- System errors

ERRTXT_PROTOCOL_NOT_DEFINED          = "Protocol not defined"
ERRTXT_PROTOCOL_INVALID              = "Invalid protocol"
ERRTXT_TYPE_CONVERSATION             = "Type conversion from '%s' to '%s' failed for parameter '%s'"
ERRTXT_DUPLICATE_DATA                = "Duplicate data (%s)"
ERRTXT_CORRUPTED_DATA                = "Corrupted data (%s)"
ERRTXT_DATABASE_OPERATION_FAILED     = "Database operation failed (%s)"
ERRTXT_EXECUTE_INSTRUCTION_FAILED    = "Execution of instruction failed (%s)"
ERRTXT_SERVICE_REQUEST_FAILED        = "Service request failed (%s)"
ERRTXT_TRIGGER_EVENT_FAILED          = "Trigger event failed (%s)"

---- Request data

INFOTXT_OBJECT_NOT_DEFINED           = "Object '%s' not defined"
INFOTXT_OBJECT_IS_EMPTY              = "Object is empty (%s)"
INFOTXT_OBJECT_NOT_VALID             = "Data object not valid (%s)"
INFOTXT_LIST_NOT_DEFINED             = "List '%s' not defined"
INFOTXT_LIST_INVALID                 = "List '%s' is invalid"
INFOTXT_PARAMETER_NOT_DEFINED        = "Parameter '%s' not defined"
INFOTXT_PARAMETER_INVALID            = "Parameter '%s' is invalid"
INFOTXT_WRONG_TYPE                   = "Wrong type (%s) for parameter '%s'"
INFOTXT_VALUE_OUT_OF_RANGE           = "Value '%s' out of range"

---- Database queries

INFOTXT_SUCCESS                      = "Changes successfully applied (%s)"
INFOTXT_NORESULT                     = "No result available (%s)"
INFOTXT_MORE_THEN_ONE_RESULT         = "More the one result available (%s)"
INFOTXT_VALUE_NOT_SET                = "A mandatory value is not set in the database (%s)"
INFOTXT_NO_DATA_AFFECTED             = "No data affected (%s)"
INFOTXT_LINKED_DATA_IS_MISSING       = "Linked data is missing (%s)"
INFOTXT_MANDATORY_VALUE_IS_NOT_SET   = "A mandatory value is not set in the database (%s)"
INFOTXT_DATA_NOT_FOUND               = "Data not found (%s)"

---- Backend communication

INFOTXT_DOM_CONTENT_NOT_AVAILABLE    = "Content locally not available (%s)"

--DB OPERATIONS
DB_OPERATION_INSERT     = 101
DB_OPERATION_UPDATE     = 102
DB_OPERATION_DELETE     = 103
-- filesystem operations
FILE_OPERATION_WRITE    = 201
FILE_OPERATION_DELETE   = 202
FILE_OPERATION_MOVE     = 203

-- Trigger instructions
TRIGGER_EVENT           = 301
TRIGGER_ACTION          = 302

-- OA Backend Instructions
BACKEND_SERVICE_REQUEST = 501
BACKEND_FILE_DOWNLOAD   = 502

FILE_TEMP_LOCATION    = "oa/tmp/"
FILE_DEFAULT_LOCATION = "oa/data/"
MEDIA_FILES_PATH      = "../carctrl/"
MEDIA_FILES_LOCATION  = "dom/media/"

HTTP_POST  = "POST"
HTTP_GET   = "GET"
HTTP_PATCH = "PATCH"

GENERIC_EVENTS = "GenericEvents"
GENERIC_EVENT  = "genericEvent"

-- table names
SYS_REQUEST = "SYS_REQUEST"

-- Global Search Constants
DEFAULT_SEARCH_TEXT_ID = 'BZ-1087'

-- engineCycle max value
MAX_INT = 32767