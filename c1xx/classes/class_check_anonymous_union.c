void __cdecl class_check_anonymous_union(byte *specs)

{
  ushort *puVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  c1_member_iter local_18;
  
  puVar1 = *(ushort **)(specs + 0x18);
  if ((g_block_depth == '\0') && (g_class_depth < 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  bVar4 = *specs;
  bVar3 = false;
  if ((bVar4 & 7) == 0) {
    *specs = ((-bVar2 & 0xfeU) + 4 ^ bVar4) & 7 ^ bVar4;
  }
  bVar4 = *specs & 7;
  if ((bVar4 != 3) && (((bVar4 < 4 || (6 < bVar4)) || (bVar2)))) {
    diag_error(0x286);
    *specs = *specs & 0xfb | 3;
  }
  if ((*puVar1 & 0x200) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(puVar1 + 4);
  }
  class_member_iter_init(&local_18,(void *)(iVar6 + 8),1);
  while (local_18.current = local_18.next, local_18.next != (void *)0x0) {
    if ((local_18.cursor.current == (void *)0x0) ||
       (local_18.cursor.current = *(void **)((int)local_18.cursor.current + 4),
       local_18.next = local_18.cursor.current, local_18.cursor.current == (void *)0x0)) {
      local_18.next = (void *)0x0;
    }
    uVar5 = class_member_iter_matches(&local_18);
    if (((char)uVar5 != '\0') && ((*(byte *)((int)local_18.current + -5) & 1) == 0)) {
      iVar6 = (int)local_18.current + -8;
      bVar4 = *(byte *)((int)local_18.current + -8) & 0x1f;
      if ((bVar4 == 3) || (bVar4 == 2)) {
        bVar3 = true;
        bVar4 = *(byte *)((int)local_18.current + -6) & 3;
        if (bVar4 < 3) {
          pcVar7 = access_specifier_name(bVar4);
          diag_error(0x272,pcVar7,iVar6);
        }
        if ((*(byte *)((int)local_18.current + 0x18) & 7) == 3) {
          if (g_ms_extensions != '\0') {
            diag_error(0x26b,0x4d,0x14d,(int)local_18.current + -8);
          }
          *(byte *)((int)local_18.current + 0x18) =
               ((-bVar2 & 0xfeU) + 4 ^ *(byte *)((int)local_18.current + 0x18)) & 7 ^
               *(byte *)((int)local_18.current + 0x18);
        }
      }
    }
  }
  if (!bVar3) {
    diag_error(0x271);
  }
  return;
}

