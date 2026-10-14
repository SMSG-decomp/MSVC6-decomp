int __cdecl cvserver_emit_type(uint length)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  c1_symbol *sym;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int local_108;
  char pdb_name [260];
  
  local_108 = 0;
  if ((g_debug_types_in_pdb != '\0') && (g_pdb.tpi == (TPI *)0x0)) {
    return 0;
  }
  uVar2 = debug_type_pad_to_4((char *)((length & 0xffff) + 2 + (int)g_debug_record_buffer),
                              (char)length + '\x02');
  uVar2 = length + uVar2;
  *g_debug_record_buffer = (ushort)uVar2;
  if (0xfafd < (ushort)uVar2) {
    diag_fatal_simple(0x43);
  }
  if (g_debug_types_in_pdb == '\0') {
    local_108 = g_cv_next_type_index;
    g_cv_next_type_index = g_cv_next_type_index + 1;
    debug_pad_record(uVar2 & 0xffff,g_debug_record_buffer);
  }
  else {
    iVar3 = TypesQueryTiForCVRecordEx(g_pdb.tpi,g_debug_record_buffer,&local_108);
    if (iVar3 == 0) {
      iVar3 = PDBQueryLastError(g_pdb.pdb,0);
      if (iVar3 != 2) {
        if (iVar3 == 8) {
          (*(g_pdb.pdb)->vtbl->QueryPDBName)(g_pdb.pdb,pdb_name);
          diag_warning(1,0xa8,pdb_name);
          return 0;
        }
        if (iVar3 != 0x10) {
          diag_fatal(1,".\\cvserver.c",0x1bc);
        }
        sym = type_emission_stack_top();
        if (sym == (c1_symbol *)0x0) {
          diag_warning(1,0x291);
        }
        else {
          iVar4 = sym_decl_position(sym);
          diag_begin_global(iVar4);
          bVar1 = sym->kind & 0x1f;
          if (bVar1 == 4) {
            iVar4 = 0x290;
          }
          else if ((bVar1 == 7) || (iVar4 = 0x28f, bVar1 == 8)) {
            iVar4 = 0x292;
          }
          diag_warning(1,iVar4,sym);
          diag_end_global();
        }
      }
      diag_fatal_simple(*(int *)(&g_pdb_error_messages + iVar3 * 4) + -1000);
    }
  }
  uVar5 = (uVar2 & 0xffff) + 2;
  puVar6 = g_debug_record_buffer;
  for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar6[0] = 0;
    puVar6[1] = 0;
    puVar6 = puVar6 + 2;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (ushort *)((int)puVar6 + 1);
  }
  return local_108;
}

