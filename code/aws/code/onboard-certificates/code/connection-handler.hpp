#ifndef CODE_AWS_EXP_ONBOARD_CERTS_CONNECTION_HANDLER
#define CODE_AWS_EXP_ONBOARD_CERTS_CONNECTION_HANDLER

void initWIFI(char ssid[], char pw[]);
void initAWS(char endpoint[], char sup_topic[]);
void pubToAWS(char message[], char topic[]);

#endif