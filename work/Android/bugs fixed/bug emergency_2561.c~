As per the analysis,the emergency numbers will start with '10'.

In phone account By default they are placing the emergency call
numbers(100,101,102,108.).

log level analysis:

Here the device is directly recognizing the emergency number when we are
dialing .so,we are not able to see the emergency numbers in dialled list.

09-26 17:00:59.248  1153  1153 I Telecom : CallsManager: Creating a new
outgoing call with handle: tel:***: PCR.oR@CTo
09-26 17:00:59.251  1153  1153 I Telecom : PhoneAccountRegistrar:
SimCallManager queried, returning: null: PCR.oR@CTo
09-26 17:00:59.251  1153  1153 I Telecom : CreateConnectionProcessor: Emergency
number detected: PCR.oR@CTo
09-26 17:00:59.251  1153  1153 I Telecom : CreateConnectionProcessor: Will try
PSTN account
ComponentInfo{com.android.phone/com.android.services.telephony.TelephonyConnectionService},
[2c52f4d01bed4fa54ced23c6c687f03de8614c40], UserHandle{0} for emergency:
PCR.oR@CTo
09-26 17:00:59.255  1153  1153 I Telecom : PhoneAccountRegistrar:
SimCallManager queried, returning: null: 



code level analysis:


If we are possibly attempting to call a local emergency number, ensure that the
    // plain PSTN connection services are listed, and nothing else.
    private void adjustAttemptsForEmergency(PhoneAccountHandle preferredPAH) {
        if (mCall.isEmergencyCall()) {
            Log.i(this, "Emergency number detected");
            mAttemptRecords.clear();
            // Phone accounts in profile do not handle emergency call, use
phone accounts in
            // current user.
            List<PhoneAccount> allAccounts = mPhoneAccountRegistrar
                .getAllPhoneAccountsOfCurrentUser();
http://androidxref.com/7.1.1_r6/xref/packages/services/Telecomm/src/com/android/server/telecom/CreateConnectionProcessor.java

*********************************
public List<PhoneAccountHandle> getCallCapablePhoneAccounts(
            String uriScheme, boolean includeDisabledAccounts, UserHandle
userHandle) {
        return getPhoneAccountHandles(
               PhoneAccount.CAPABILITY_CALL_PROVIDER,
                PhoneAccount.CAPABILITY_EMERGENCY_CALLS_ONLY
/*excludedCapabilities*/,
                uriScheme, null, includeDisabledAccounts, userHandle);
    })
http://androidxref.com/7.1.1_r6/xref/packages/services/Telecomm/src/com/android/server/telecom/PhoneAccountRegistrar.java

****************************

Flag indicating that this {@code PhoneAccount} is capable of placing emergency
calls.
     * By default all PSTN {@code PhoneAccount}s are capable of placing
emergency calls.
     * <p>
     * See {@link #getCapabilities}
     */
    public static final int CAPABILITY_PLACE_EMERGENCY_CALLS = 0x10;
http://androidxref.com/7.1.1_r6/xref/frameworks/base/telecomm/java/android/telecom/PhoneAccount.java
