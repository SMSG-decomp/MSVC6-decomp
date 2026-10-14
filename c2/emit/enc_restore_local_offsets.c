void __fastcall enc_restore_local_offsets(c2_pdb_func_syms *fs)

{
  uint8_t *puVar1;
  byte bVar2;
  c2_fe_symbol *s;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  c2_fe_symbol *match;
  c2_fe_symbol *pcVar7;
  bool bVar8;
  c2_pdb_sym_var *sym_var;
  c2_pdb_enum_sym_vars *enum_locals;
  c2_enc_local *cell;
  int frame_floor;
  uint32_t type_index;
  byte name_buf [256];
  
  frame_floor = g_frame_cursor;
  iVar3 = FSGetEnumLocals(fs,&enum_locals);
  if (iVar3 != 0) {
    iVar3 = ESVNext(enum_locals);
    while (iVar3 != 0) {
      ESVGet(enum_locals,&sym_var);
      SVName(sym_var,name_buf);
      type_index = SVTypeIndex(sym_var);
      iVar3 = SVOffBP(sym_var);
      SVRelease(sym_var);
      if (iVar3 <= g_frame_cursor) {
        g_frame_cursor = iVar3;
      }
      cell = g_enc_local_list;
      match = (c2_fe_symbol *)0x0;
      do {
        if (cell == (c2_enc_local *)0x0) {
          if (match == (c2_fe_symbol *)0x0) goto LAB_10793893;
          break;
        }
        s = cell->sym;
        pcVar7 = match;
        if ((s->cv_type_index == type_index) && (s->name != (char *)0x0)) {
          pbVar4 = (byte *)fe_symbol_name(s,0);
          pbVar6 = name_buf;
          do {
            bVar2 = *pbVar6;
            bVar8 = bVar2 < *pbVar4;
            if (bVar2 != *pbVar4) {
LAB_10793878:
              iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_1079383d;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar6[1];
            bVar8 = bVar2 < pbVar4[1];
            if (bVar2 != pbVar4[1]) goto LAB_10793878;
            pbVar6 = pbVar6 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_1079383d:
          if (((iVar5 == 0) && (pcVar7 = s, (s->attrs & 0x800) != 0)) &&
             (iVar5 = s->offset, pcVar7 = match, iVar5 < iVar3)) {
            s->offset = iVar3;
            iVar3 = iVar5;
          }
        }
        cell = cell->next;
        match = pcVar7;
      } while (pcVar7 == (c2_fe_symbol *)0x0);
      if (iVar3 <= frame_floor) {
        match->offset = iVar3;
        match->attrs = match->attrs | 0x800;
        if (match->storage_sym != (c2_symbol *)0x0) {
          puVar1 = &match->storage_sym->flags5;
          *puVar1 = *puVar1 | 0x20;
        }
      }
LAB_10793893:
      iVar3 = ESVNext(enum_locals);
    }
    ESVRelease(enum_locals);
  }
  return;
}

