byte __cdecl import_typedesc_equal(void *a,void *b)

{
  short sVar1;
  ushort uVar2;
  void *b_00;
  void *a_00;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  sVar1 = *(short *)((int)a + 4);
  if (sVar1 != *(short *)((int)b + 4)) {
    return 0;
  }
  do {
    switch(sVar1) {
    case 0x1a:
    case 0x1b:
      a = *(void **)a;
      b = *(void **)b;
      sVar1 = *(short *)((int)a + 4);
      if (sVar1 != *(short *)((int)b + 4)) {
        return 0;
      }
      break;
    case 0x1c:
      b_00 = *(void **)b;
      a_00 = *(void **)a;
      bVar3 = import_typedesc_equal(a_00,b_00);
      if (bVar3 == 0) {
        return 0;
      }
      uVar2 = *(ushort *)((int)a_00 + 8);
      if (uVar2 == *(ushort *)((int)b_00 + 8)) {
        uVar5 = 0;
        if (uVar2 == 0) {
          return 1;
        }
        piVar6 = (int *)((int)b_00 + 0x10);
        piVar4 = (int *)((int)a_00 + 0xc);
        while( true ) {
          if (*piVar4 != *(int *)(((int)b_00 - (int)a_00) + (int)piVar4)) {
            return 0;
          }
          if (piVar4[1] != *piVar6) break;
          uVar5 = uVar5 + 1;
          piVar4 = piVar4 + 2;
          piVar6 = piVar6 + 2;
          if (uVar2 <= uVar5) {
            return 1;
          }
        }
        return 0;
      }
      return 0;
    case 0x1d:
      return *(int *)a == *(int *)b;
    default:
      return 1;
    }
  } while( true );
}

