byte __cdecl member_path_offset(int *path,int *vbase,int *offset)

{
  byte *pbVar1;
  byte bVar2;
  
  *offset = 0;
  *vbase = 0;
  if (path != (int *)0x0) {
    while (pbVar1 = (byte *)path[2], (*pbVar1 & 0x1f) != 4) {
      if ((pbVar1[0x1a] & 1) != 0) {
        *vbase = (int)pbVar1;
        bVar2 = member_path_offset_tail(0);
        return bVar2;
      }
      *offset = *offset + *(int *)(pbVar1 + 0x14);
      path = (int *)*path;
      if (path == (int *)0x0) {
        bVar2 = member_path_offset_end(1);
        return bVar2;
      }
    }
  }
  return 1;
}

