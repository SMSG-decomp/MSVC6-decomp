c2_fe_symbol * __fastcall extern_symbol_lookup_or_create(uint8_t *s)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  c2_fe_symbol *pcVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  bool bVar9;
  
  uVar2 = string_byte_sum((char *)s);
  uVar2 = uVar2 & 0x7f;
  pcVar5 = g_extern_name_hash[uVar2];
  uVar8 = uVar2;
  do {
    if (pcVar5 == (c2_fe_symbol *)0x0) {
      if (g_opt_incremental != 0) {
        g_fe_forced_local_id = uVar8 - 0x81;
      }
      pcVar5 = fe_symbol_new_local_cur(3,g_ptr_type & 0xfff,2,0,'\x02',0);
      g_fe_forced_local_id = 0;
      g_extern_name_hash[uVar8] = pcVar5;
      pcVar6 = arena_strdup((char *)s,0);
      pcVar5->name = pcVar6;
      pcVar5->role = 'Z';
      note_symbol_referenced(pcVar5);
      return pcVar5;
    }
    pbVar3 = (byte *)g_extern_name_hash[uVar8]->name;
    pbVar7 = s;
    do {
      bVar1 = *pbVar3;
      bVar9 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_107839d5:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_107540bb;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar9 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_107839d5;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_107540bb:
    if (iVar4 == 0) {
      if (g_opt_incremental != 0) {
        note_symbol_referenced(g_extern_name_hash[uVar8]);
      }
      return g_extern_name_hash[uVar8];
    }
    uVar8 = uVar8 + 1 & 0x7f;
    if (uVar8 == uVar2) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x7bb);
    }
    pcVar5 = g_extern_name_hash[uVar8];
  } while( true );
}

