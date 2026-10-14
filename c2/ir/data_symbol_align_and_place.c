void __fastcall data_symbol_align_and_place(c2_fe_symbol *fs)

{
  c2_fe_symbol *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_fe_symbol *pcVar3;
  uint uVar4;
  
  pcVar2 = fe_symbol_lookup_id(fs->section_id);
  if (pcVar2 == (c2_fe_symbol *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x45d);
  }
  pcVar1 = (c2_fe_symbol *)fs->size;
  pcVar3 = pcVar1;
  if ((fs->storage & 0x10000) != 0) {
    pcVar3 = *(c2_fe_symbol **)((int)&(fs->u3e).label_flags + 2);
    if ((int)pcVar3 < 9) {
      if ((int)pcVar3 < 4) {
        pcVar3 = (c2_fe_symbol *)0x4;
      }
      else if (8 < (int)pcVar3) goto LAB_10750487;
    }
    else {
LAB_10750487:
      pcVar3 = (c2_fe_symbol *)0x8;
    }
  }
  if ((((g_opt_cpu_target < 4) || ((int)pcVar3 < 8)) || ((pcVar2->u3e).label_flags != 4)) ||
     ((fs->attrs & 0x400) != 0)) {
    if (g_opt_bzalign != 0) goto LAB_1076a9c2;
LAB_1075045c:
    if (((int)pcVar3 < 8) || ((fs->attrs & 0x400) != 0)) {
      if ((int)(pcVar2->u3e).alias_base <= (int)pcVar3) {
        pcVar3 = (pcVar2->u3e).alias_base;
      }
      goto LAB_1075046a;
    }
  }
  else {
    if (g_opt_bzalign == 0) {
      (pcVar2->u3e).label_flags = 8;
      goto LAB_1075045c;
    }
LAB_1076a9c2:
    if ((pcVar1 < (c2_fe_symbol *)0x5) || ((fs->attrs & 0x400) != 0)) {
      pcVar3 = (pcVar2->u3e).alias_base;
      if (4 < (int)pcVar3) {
        pcVar3 = (c2_fe_symbol *)0x4;
      }
      goto LAB_1075046a;
    }
  }
  pcVar3 = (pcVar2->u3e).alias_base;
  if (8 < (int)pcVar3) {
    pcVar3 = (c2_fe_symbol *)0x8;
  }
LAB_1075046a:
  uVar4 = pcVar2->offset + -1 + (int)pcVar3 & ~(uint)((int)&pcVar3[-1].x77 + 3);
  fs->offset = uVar4;
  pcVar2->offset = (int)&pcVar1->next + uVar4;
  return;
}

