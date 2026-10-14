void __cdecl file_name_canonicalize(byte *name)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = *name;
  pbVar2 = name;
  while (bVar1 != 0) {
    name = (byte *)(uint)bVar1;
    if (g_file_name_case_table[(int)name] == 0xffff) {
      pbVar2 = pbVar2 + 2;
    }
    else {
      *pbVar2 = (byte)g_file_name_case_table[(int)name];
      pbVar2 = pbVar2 + 1;
    }
    bVar1 = *pbVar2;
  }
  return;
}

