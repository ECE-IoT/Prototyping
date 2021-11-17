# AWS code structure 

In order to create a reusable vertical prototype a certain code-structure should be given. Therefore the AWS service handler functions are built up within an `AWS` class. 

## Symbolic state diagramm  

```mermaid
stateDiagram-v2
    [*] --> initWifi

    state initWifi {
        [*] --> handleWifi: wifi connection like Arduino
    }

    initWifi --> createTLSClient

    state createTLSClient {
        [*] --> createTLSclient
        createTLSclient --> loadCertificationFiles : from SPIFFs
        loadCertificationFiles --> createTLSclient : return Files
        state checkTLS <<choice>>
        createTLSclient --> checkTLS: connection
        checkTLS --> validTLS
        checkTLS --> invalidTLS
        invalidTLS --> checkTLS 
        validTLS --> returnTLSClient
    }

    returnTLSClient --> createMQTTClient

    state createMQTTClient {
        initMQTTClient --> TLSClientForMQTT: give TLS client to MQTT client
        state connectToBroker <<choice>>
        TLSClientForMQTT --> connectToBroker
        connectToBroker --> successMQTT
        connectToBroker --> failedMQTT
        failedMQTT --> connectToBroker
        successMQTT --> returnMQTTClient
        successMQTT --> subscribeToGiveTopic
    }

    returnMQTTClient --> publish

    state publish {
        [*] --> handlePublishing: to Topics with any Payload
    }

    subscribeToGiveTopic --> subscribe

    state subscribe {
        [*] --> handleSubscribing: to given Topic
    }

```