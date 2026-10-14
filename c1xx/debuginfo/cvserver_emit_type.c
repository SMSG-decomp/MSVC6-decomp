int __cdecl cvserver_emit_type(ushort length)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  c1_symbol *sym;
  c1_u32 position;
  int n;
  uint uVar5;
  ushort *puVar6;
  int local_108;
  char pdb_name [260];
  
  uVar1 = length;
  _length = (uint)length;
  local_108 = 0;
  if ((g_debug_types_in_pdb != '\0') && (g_pdb.tpi == (c1_pdb_tpi *)0x0)) {
    return 0;
  }
  uVar3 = debug_type_pad_to_4((char *)(uVar1 + 2 + (int)g_debug_record_buffer),(char)uVar1 + '\x02')
  ;
  _length = _length + uVar3;
  *g_debug_record_buffer = (ushort)_length;
  if (0xfafd < (ushort)_length) {
    diag_fatal_simple(0x43);
  }
  if (g_debug_types_in_pdb == '\0') {
    local_108 = g_cv_next_type_index;
    g_cv_next_type_index = g_cv_next_type_index + 1;
    debug_pad_record(_length & 0xffff,g_debug_record_buffer);
  }
  else {
    iVar4 = TypesQueryTiForCVRecordEx(g_pdb.tpi,g_debug_record_buffer,&local_108);
    if (iVar4 == 0) {
      iVar4 = PDBQueryLastError(g_pdb.pdb,0);
      if (iVar4 != 2) {
        if (iVar4 == 8) {
          (*(g_pdb.pdb)->vtbl->query_pdb_name)(g_pdb.pdb,pdb_name);
          diag_warning(1,0xa8,pdb_name);
          return 0;
        }
        if (iVar4 != 0x10) {
          diag_fatal(1,".\\cvserver.c",0x1bc);
        }
        sym = type_emission_stack_top();
        if (sym == (c1_symbol *)0x0) {
          diag_warning(1,0x291);
        }
        else {
          position = sym_decl_position(sym);
          diag_begin_global(position);
          bVar2 = sym->kind & 0x1f;
          if (bVar2 == 4) {
            n = 0x290;
          }
          else if ((bVar2 == 7) || (n = 0x28f, bVar2 == 8)) {
            n = 0x292;
          }
          diag_warning(1,n,sym);
          diag_end_global();
        }
      }
      diag_fatal_simple(g_pdb_error_messages[iVar4] + -1000);
    }
  }
  uVar5 = (_length & 0xffff) + 2;
  puVar6 = g_debug_record_buffer;
  for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
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

