void * __cdecl segment_lookup_or_declare(void *name,void *seg_class,char cls)

{
  c1_u8 cVar1;
  uint id;
  c1_symbol *seg;
  c1_symbol *pcVar2;
  int iVar3;
  int iVar4;
  short n;
  
  seg = (c1_symbol *)scope_lookup_segment(g_current_scope,(int)name);
  if (seg == (c1_symbol *)0x0) {
    if (cls == '\b') {
      iVar3 = str_ends_with(*(char **)((int)name + 4),"_TEXT");
      if (iVar3 != 0) {
        cls = '\x02';
      }
    }
    id = g_next_entity_id;
    if (g_next_entity_id < 0x7fffffff) {
      g_next_entity_id = g_next_entity_id + 1;
      pcVar2 = sym_new_builtin(name,seg_class,id,cls);
      return pcVar2;
    }
    diag_fatal_simple(0x37);
  }
  if ((cls != '\b') && (cVar1 = (seg->x28).bytes.bit_position, cls != cVar1)) {
    if ((cls == '\0') || (cls == '\x02')) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
    if ((cVar1 == '\0') || (cVar1 == '\x02')) {
      iVar4 = 1;
    }
    else {
      iVar4 = 0;
    }
    if (iVar3 != iVar4) {
      if (((cVar1 == '\0') || (cVar1 == '\x02')) && ((seg->entity & 0xffffff) != 5)) {
        n = 0xc2;
      }
      else {
        if (cls == '\x01') goto LAB_10611e0f;
        n = 0xc3;
      }
      diag_error(n,seg);
    }
  }
LAB_10611e0f:
  if ((seg_class != (void *)0x0) && (seg_class != g_name_unnamed)) {
    if ((seg->detail == (fe_name *)0x0) || (seg->detail == g_name_unnamed)) {
      seg->detail = seg_class;
    }
    if (seg_class != seg->detail) {
      diag_warning(1,0x265,seg);
    }
  }
  if ((((seg->entity & 0xffffff) == 5) && ((g_compile_flags_c4 & 0x20000) != 0)) &&
     ((g_current_function->flags23 & 1) != 0)) {
    seg = sym_segment_record(g_current_function);
  }
  if ((g_code_seg_name != (void *)0x0) && ((seg->entity & 0xffffff) == 5)) {
    seg = g_code_seg_name;
  }
  if ((g_data_seg_name != (void *)0x0) && ((seg->entity & 0xffffff) == 2)) {
    seg = g_data_seg_name;
  }
  if (((seg->x28).bytes.bit_position == '\x02') && (cls == '\0')) {
    (seg->x28).bytes.bit_position = '\0';
  }
  return seg;
}

