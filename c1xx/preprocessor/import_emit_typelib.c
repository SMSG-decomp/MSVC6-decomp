byte __cdecl import_emit_typelib(c1_itypelib *typelib)

{
  c1_u8 *item;
  c1_u8 *_Dest;
  c1_import_enum_table *pcVar1;
  c1_vector *pcVar2;
  byte bVar3;
  long lVar4;
  uint count;
  wchar_t *name;
  uint index;
  FILE *pFVar5;
  size_t sVar6;
  int iVar7;
  short sVar8;
  c1_u32 *pcVar9;
  c1_u32 *pcVar10;
  uint uVar11;
  bool bVar12;
  int *piStack_a8;
  void *pvStack_a4;
  wchar_t *pwStack_a0;
  wchar_t *pwStack_9c;
  uint *lib_attr;
  uint tli_buffer [6];
  uint smartptr_size;
  uint smartptr_unk0c;
  uint smartptr_unk10;
  uint items_buffer [6];
  uint guids_size;
  uint guids_unk0c;
  uint guids_unk10;
  uint mapping_buffer [6];
  uint fwdrefs_size;
  uint fwdrefs_unk0c;
  uint fwdrefs_unk10;
  c1_import_depgraph depgraph;
  
  lVar4 = (*typelib->vtbl->GetLibAttr)(typelib,&lib_attr);
  if (lVar4 < 0) {
    diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
  }
  g_import_missing_typelib_reported = 0;
  pwStack_9c = (wchar_t *)0x0;
  if (g_import_namespace == (wchar_t *)0x0) {
    lVar4 = (*typelib->vtbl->GetDocumentation)
                      (typelib,-1,&pwStack_9c,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
    if (lVar4 < 0) {
      diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
    }
    g_import_namespace = import_apply_rename(pwStack_9c);
  }
  g_import_libid[0] = *lib_attr;
  g_import_libid[1] = lib_attr[1];
  g_import_libid[2] = lib_attr[2];
  g_import_libid[3] = lib_attr[3];
  if (g_import_dual_interfaces == 0) {
    iVar7 = 4;
    bVar12 = true;
    pcVar9 = g_import_libid;
    pcVar10 = &g_import_libid_excel5;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar12 = *pcVar9 == *pcVar10;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    } while (bVar12);
    if (((bVar12) && ((short)lib_attr[6] == 1)) && (*(short *)((int)lib_attr + 0x1a) == 2)) {
      g_import_no_dual_interfaces = 1;
    }
  }
  count = (*typelib->vtbl->GetTypeInfoCount)(typelib);
  if ((g_import_implementation_only == 0) && (g_import_no_implementation == 0)) {
    if (g_import_function_mapping_default != 0) {
      iVar7 = import_count_wrapper_functions(typelib,count);
      g_import_function_mapping = 499 < iVar7;
    }
    if (g_import_function_mapping != 0) {
      g_import_implementation_key = 1;
    }
  }
  else {
    g_import_function_mapping_default = 0;
    g_import_function_mapping = 0;
  }
  import_write_file_banners(lib_attr[5]);
  g_import_forward_refs = (c1_il_buffer *)(mapping_buffer + 5);
  g_import_items = (c1_il_buffer *)items_buffer;
  g_import_smartptr_typedefs = (c1_il_buffer *)(tli_buffer + 5);
  g_import_tli_implementations = (c1_il_buffer *)tli_buffer;
  g_import_named_guid_inits = (c1_il_buffer *)(items_buffer + 5);
  g_import_mapping = (c1_il_buffer *)mapping_buffer;
  mapping_buffer[5] = 0;
  items_buffer[0] = 0;
  items_buffer[1] = 0;
  items_buffer[2] = 0;
  items_buffer[3] = 0;
  items_buffer[4] = 0;
  tli_buffer[0] = 0;
  tli_buffer[1] = 0;
  tli_buffer[2] = 0;
  tli_buffer[3] = 0;
  tli_buffer[4] = 0;
  tli_buffer[5] = 0;
  items_buffer[5] = 0;
  mapping_buffer[0] = 0;
  mapping_buffer[1] = 0;
  mapping_buffer[2] = 0;
  mapping_buffer[3] = 0;
  mapping_buffer[4] = 0;
  import_write_named_guid(g_import_libid,"LIB",g_import_namespace);
  g_import_cross_referenced_libs = (c1_vector *)0x0;
  import_depgraph_init(&depgraph,count);
  uVar11 = 0;
  if (count != 0) {
    do {
      lVar4 = (*typelib->vtbl->GetTypeInfo)(typelib,uVar11,&piStack_a8);
      if (lVar4 < 0) {
        diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
      }
      lVar4 = (**(code **)(*piStack_a8 + 0xc))(piStack_a8,&pvStack_a4);
      if (lVar4 < 0) {
        diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
      }
      lVar4 = (**(code **)(*piStack_a8 + 0x30))
                        (piStack_a8,-1,&pwStack_a0,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
      if (lVar4 < 0) {
        diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
      }
      bVar3 = import_is_excluded(pwStack_a0,*(int *)((int)pvStack_a4 + 0x28));
      if (bVar3 == 0) {
        name = import_apply_rename(pwStack_a0);
        import_write_forward_reference(piStack_a8,pvStack_a4,name);
        import_collect_dependencies(piStack_a8,pvStack_a4,uVar11,&depgraph);
        bVar3 = import_depgraph_is_ready(&depgraph,uVar11);
        if (bVar3 != 0) {
          import_emit_type_item(piStack_a8,pvStack_a4,name);
          goto LAB_104a16a4;
        }
        SysFreeString(pwStack_a0);
        (**(code **)(*piStack_a8 + 0x4c))(piStack_a8,pvStack_a4);
        (**(code **)(*piStack_a8 + 8))(piStack_a8);
      }
      else {
LAB_104a16a4:
        SysFreeString(pwStack_a0);
        (**(code **)(*piStack_a8 + 0x4c))(piStack_a8,pvStack_a4);
        (**(code **)(*piStack_a8 + 8))(piStack_a8);
        import_depgraph_mark_emitted(&depgraph,uVar11);
        index = import_depgraph_next_ready(&depgraph);
        while (index <= uVar11) {
          import_emit_deferred_item(typelib,index);
          import_depgraph_mark_emitted(&depgraph,index);
          index = import_depgraph_next_ready(&depgraph);
        }
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < count);
  }
  uVar11 = import_depgraph_first_pending(&depgraph);
  while (uVar11 < count) {
    import_emit_deferred_item(typelib,uVar11);
    import_depgraph_force_emit(&depgraph,uVar11);
    uVar11 = import_depgraph_next_ready(&depgraph);
    while (uVar11 < count) {
      import_emit_deferred_item(typelib,uVar11);
      import_depgraph_mark_emitted(&depgraph,uVar11);
      uVar11 = import_depgraph_next_ready(&depgraph);
    }
    uVar11 = import_depgraph_first_pending(&depgraph);
  }
  import_write_cross_referenced_libraries();
  import_write_pragma_once_pack();
  if (g_import_no_namespace == 0) {
    pFVar5 = g_import_tli_file;
    if (g_import_implementation_only == 0) {
      pFVar5 = g_import_tlh_file;
    }
    fprintf((FILE *)pFVar5,"\nnamespace %S {\n",g_import_namespace);
  }
  if (g_import_implementation_only == 0) {
    if ((g_import_injected_statements != (c1_vector *)0x0) &&
       (g_import_injected_statements->count != 0)) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// User-injected statements\n//\n\n");
      pcVar2 = g_import_injected_statements;
      for (sVar8 = 0; (pcVar2 != (c1_vector *)0x0 && ((int)sVar8 < (int)(uint)pcVar2->count));
          sVar8 = sVar8 + 1) {
        fprintf((FILE *)g_import_tlh_file,"%s\n",pcVar2->data[sVar8]);
      }
      if (g_import_implementation_only != 0) goto LAB_104a186a;
    }
    if (mapping_buffer[5] != 0) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// Forward references and typedefs\n//\n\n");
      import_flush_text_to_file
                ((c1_il_buffer *)(mapping_buffer + 5),g_import_tlh_file,g_import_tlh_path);
    }
    if (tli_buffer[5] != 0) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// Smart pointer typedef declarations\n//\n\n");
      import_flush_text_to_file
                ((c1_il_buffer *)(tli_buffer + 5),g_import_tlh_file,g_import_tlh_path);
    }
    if (items_buffer[1] != items_buffer[0]) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// Type library items\n//\n");
      import_flush_text_to_file((c1_il_buffer *)items_buffer,g_import_tlh_file,g_import_tlh_path);
    }
    if (items_buffer[5] != 0) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// Named GUID constants initializations\n//\n\n");
      import_flush_text_to_file
                ((c1_il_buffer *)(items_buffer + 5),g_import_tlh_file,g_import_tlh_path);
    }
    if ((g_import_function_mapping != 0) && (mapping_buffer[1] != mapping_buffer[0])) {
      fprintf((FILE *)g_import_tlh_file,"\n//\n// Function implementation mapping\n//\n\n");
      fprintf((FILE *)g_import_tlh_file,"#pragma start_map_region(\"%s\")\n",g_import_tli_path);
      import_flush_text_to_file((c1_il_buffer *)mapping_buffer,g_import_tlh_file,g_import_tlh_path);
      fprintf((FILE *)g_import_tlh_file,"#pragma stop_map_region\n");
      goto LAB_104a186a;
    }
    if (g_import_no_implementation != 0) goto LAB_104a1897;
    if (tli_buffer[1] != tli_buffer[0]) {
      fprintf((FILE *)g_import_tlh_file,
              "\n//\n// Wrapper method implementations\n//\n\n#include \"%s\"\n",g_import_tli_path);
      goto LAB_104a186a;
    }
  }
  else {
LAB_104a186a:
    if (g_import_no_implementation != 0) goto LAB_104a1897;
  }
  if (tli_buffer[1] == tli_buffer[0]) {
    rewind((FILE *)g_import_tli_file);
  }
  else {
    import_flush_text_to_file((c1_il_buffer *)tli_buffer,g_import_tli_file,g_import_tli_path);
  }
LAB_104a1897:
  if (g_import_no_namespace == 0) {
    pFVar5 = g_import_tli_file;
    if (g_import_implementation_only == 0) {
      pFVar5 = g_import_tlh_file;
    }
    fprintf((FILE *)pFVar5,"\n} // namespace %S\n",g_import_namespace);
  }
  import_write_pack_pop();
  pcVar1 = g_import_enum_table;
  if (g_import_enum_table != (c1_import_enum_table *)0x0) {
    import_enum_table_free(g_import_enum_table);
    __3_YAXPAX_Z(pcVar1);
    g_import_enum_table = (c1_import_enum_table *)0x0;
  }
  if (g_imported_libraries == (c1_vector *)0x0) {
    g_imported_libraries = vector_new(0,0);
  }
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x14;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_u32 *)item = g_import_libid[0];
  *(c1_u32 *)(item + 4) = g_import_libid[1];
  *(c1_u32 *)(item + 8) = g_import_libid[2];
  *(c1_u32 *)(item + 0xc) = g_import_libid[3];
  if (g_import_no_namespace == 0) {
    sVar6 = wcslen(g_import_namespace);
    _Dest = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + (sVar6 * 2 + 5 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_u8 **)(item + 0x10) = _Dest;
    wcscpy((wchar_t *)_Dest,g_import_namespace);
  }
  else {
    item[0x10] = '\0';
    item[0x11] = '\0';
    item[0x12] = '\0';
    item[0x13] = '\0';
  }
  vector_push(g_imported_libraries,item);
  SysFreeString(pwStack_9c);
  (*typelib->vtbl->ReleaseTLibAttr)(typelib,lib_attr);
  if (mapping_buffer[0] != 0) {
    __3_YAXPAX_Z((void *)mapping_buffer[0]);
    mapping_buffer[2] = 0;
  }
  if (items_buffer[5] != 0) {
    __3_YAXPAX_Z((void *)items_buffer[5]);
  }
  if (tli_buffer[5] != 0) {
    __3_YAXPAX_Z((void *)tli_buffer[5]);
  }
  if (tli_buffer[0] != 0) {
    __3_YAXPAX_Z((void *)tli_buffer[0]);
    tli_buffer[2] = 0;
  }
  if (items_buffer[0] != 0) {
    __3_YAXPAX_Z((void *)items_buffer[0]);
    items_buffer[2] = 0;
  }
  if (mapping_buffer[5] != 0) {
    __3_YAXPAX_Z((void *)mapping_buffer[5]);
  }
  return 1;
}

