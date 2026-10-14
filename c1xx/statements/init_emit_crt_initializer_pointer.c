void __cdecl init_emit_crt_initializer_pointer(c1_symbol *fn)

{
  void *pvVar1;
  void *pvVar2;
  c1_node *pcVar3;
  c1_symbol *pcVar4;
  c1_type *type;
  char cls;
  uint mode;
  
  if (g_crt_initializer_segment == (void *)0x0) {
    if (g_init_seg_kind == 5) {
      g_crt_initializer_segment = segment_lookup_or_declare(g_init_seg_name,g_name_unnamed,'\b');
    }
    else {
      g_crt_initializer_segment = (void *)0x0;
      while (g_crt_segments_to_declare != 0) {
        g_crt_segments_to_declare = g_crt_segments_to_declare + -1;
        cls = '\x01';
        pvVar1 = name_intern("DATA");
        pvVar2 = name_intern((&PTR_s__CRT_XCA_104c66e8)[g_crt_segments_to_declare]);
        segment_lookup_or_declare(pvVar2,pvVar1,cls);
      }
      pvVar1 = name_intern((&PTR_s__CRT_XCA_104c66e8)[g_init_seg_kind]);
      g_crt_initializer_segment = scope_lookup_segment(g_current_scope,pvVar1);
    }
  }
  mode = 4;
  pcVar3 = tree_new_symbol_ref(fn,'\x01');
  pcVar3 = expr_build_address_of(pcVar3,mode);
  type = pcVar3->type;
  pvVar1 = g_crt_initializer_segment;
  pvVar2 = name_new_S();
  pcVar4 = sym_new_static_in_segment(pvVar2,type,pvVar1);
  pcVar4->flags4 = pcVar4->flags4 | 4;
  pcVar4 = init_begin_variable(pcVar4);
  decl_finish_initialization(pcVar4,pcVar3);
  if (g_init_seg_kind != 5) {
    g_crt_initializer_segment = (void *)0x0;
  }
  return;
}

