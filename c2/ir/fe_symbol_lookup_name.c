c2_fe_symbol * __fastcall fe_symbol_lookup_name(char *name)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  c2_fe_symbol *pcVar5;
  uint32_t uVar6;
  char *pcVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  
  uVar2 = string_byte_sum(name);
  uVar2 = uVar2 & 0x7f;
  pcVar5 = g_extern_name_hash[uVar2];
  uVar9 = uVar2;
  do {
    if (pcVar5 == (c2_fe_symbol *)0x0) {
      pcVar5 = fe_symbol_alloc('\x04',0);
      bVar10 = g_opt_incremental == 0;
      g_extern_name_hash[uVar9] = pcVar5;
      pcVar5->cls = '\x04';
      if (bVar10) {
        uVar6 = fe_symbol_next_id();
        pcVar5->id = uVar6;
      }
      else {
        pcVar5->id = uVar9 - 0x81;
      }
      pcVar7 = arena_strdup(name,0);
      pcVar5->name = pcVar7;
      pcVar5->flags31 = pcVar5->flags31 & 0xfc;
      pcVar5->attrs = 0;
      pcVar5->storage = CONCAT31((int3)(pcVar5->storage >> 8),0x47);
      note_symbol_referenced(pcVar5);
      pcVar5->storage = pcVar5->storage & 0xfffff9ff | 0x100;
      fe_symbol_hash_insert(pcVar5,0);
      return pcVar5;
    }
    pbVar3 = (byte *)g_extern_name_hash[uVar9]->name;
    pbVar8 = (byte *)name;
    do {
      bVar1 = *pbVar3;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_10783a32:
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10750d71;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_10783a32;
      pbVar3 = pbVar3 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_10750d71:
    if (iVar4 == 0) {
      if (g_opt_incremental != 0) {
        note_symbol_referenced(g_extern_name_hash[uVar9]);
      }
      return g_extern_name_hash[uVar9];
    }
    uVar9 = uVar9 + 1 & 0x7f;
    if (uVar9 == uVar2) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x7e6);
    }
    pcVar5 = g_extern_name_hash[uVar9];
  } while( true );
}

