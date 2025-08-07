

doc pduR_Data


getCanFrameFormat: CanFD?


check pduR_Data -> build SF, FF, CF, FC frames.

FD
data <= 63
    fill phCanTp_SF_t
    set canTpState = SF

data >63
    tinhs seqNum,
    tach ra nhieu frame, luu CF --- queue

    set flagSending
    set canTpState = FF


CanTpMainFunction()
{
    check flagSending
        CanTpProcess();
}

CanTpProcess()
{
    switch (canTpState)
    {
    case SF:
        /* code */
        send;
        clear flagSending;
        break;
    case FF:
        send();
        sw to WaitFC
        /* code */
        break;
    case CF:
        
        /* code */
        break;
    case WaitFC:
        get FC frame;
        CF
        /* code */
        break;
    case Idle:
        /* code */
        break;
    default:
        break;
    }
}