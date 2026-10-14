void __cdecl class_check_uuid_redefinition(c1_symbol *sym,c1_u8 *spec)

{
  undefined4 *puVar1;
  c1_u8 *value;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  value = g_arenas[0].cur;
  if ((spec[1] & 0x40) != 0) {
    if ((sym->flags21 & 0x40) == 0) {
      puVar1 = *(undefined4 **)(spec + 0xc);
      if (puVar1 == (undefined4 *)0x0) {
        sym->flags21 = sym->flags21 & 0xbf;
        return;
      }
      g_arenas[0].cur = g_arenas[0].cur + 0x10;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (value != (c1_u8 *)0x0) {
        *(undefined4 *)value = *puVar1;
        *(undefined4 *)(value + 4) = puVar1[1];
        *(undefined4 *)(value + 8) = puVar1[2];
        *(undefined4 *)(value + 0xc) = puVar1[3];
        sym_attach_extra(sym,value);
        return;
      }
      sym_attach_extra(sym,(void *)0x0);
    }
    else {
      piVar2 = sym_extra_record(sym);
      iVar3 = 4;
      bVar5 = true;
      piVar4 = *(int **)(spec + 0xc);
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar5 = *piVar2 == *piVar4;
        piVar2 = piVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (bVar5);
      if (!bVar5) {
        diag_error(0x16f,sym);
        return;
      }
    }
  }
  return;
}

