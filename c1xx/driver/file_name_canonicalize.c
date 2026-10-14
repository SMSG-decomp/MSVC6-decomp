byte * __cdecl file_name_canonicalize(byte *name)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = name;
  bVar1 = *name;
  pbVar3 = name;
  while (bVar1 != 0) {
    name = (byte *)(uint)bVar1;
    if (g_file_name_case_table[(int)name] == 0xffff) {
      pbVar3 = pbVar3 + 2;
    }
    else {
      *pbVar3 = (byte)g_file_name_case_table[(int)name];
      pbVar3 = pbVar3 + 1;
    }
    bVar1 = *pbVar3;
  }
  return pbVar2;
}

