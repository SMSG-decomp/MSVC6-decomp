void __cdecl func_check_argument_bytes(int sym)

{
  int iVar1;
  
  iVar1 = func_parameter_bytes
                    (*(c1_type **)
                      (((uint)*(byte **)(sym + 0x14) &
                       -(uint)((**(byte **)(sym + 0x14) & 0x80) != 0)) + 8));
  if (iVar1 < 0x10000) {
    *(short *)(sym + 0x2c) = (short)iVar1;
    *(byte *)(sym + 5) = *(byte *)(sym + 5) | 0x40;
    return;
  }
  diag_fatal(0x1fc,sym);
}

