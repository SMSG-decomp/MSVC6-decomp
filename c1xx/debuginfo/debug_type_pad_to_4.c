uint __cdecl debug_type_pad_to_4(char *out,char length)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = (byte)-length & 3;
  cVar3 = (char)uVar1 + -0x10;
  if ((short)uVar1 != 0) {
    iVar2 = (uVar1 + 0xffff & 0xffff) + 1;
    do {
      *out = cVar3;
      out = out + 1;
      cVar3 = cVar3 + -1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return uVar1;
}

