void GetHeight(BT)
{
    int HL, HR, HMAX;
    if (BT)
    {
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        HAMX = HL > HR ? HL : HR;
        return (HMAX + 1);
    }
    else
        return 0;


}
