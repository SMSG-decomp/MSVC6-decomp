void * __cdecl segment_lookup_or_declare(void *name,void *seg_class,char cls)

{
  c1_u8 cVar1;
  uint id;
  c1_symbol *pcVar2;
  int iVar3;
  int iVar4;
  short n;
  
  pcVar2 = (c1_symbol *)scope_lookup_segment(g_current_scope,name);
  if (pcVar2 == (c1_symbol *)0x0) {
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
  if ((cls != '\b') && (cVar1 = (pcVar2->x28).bytes.bit_position, cls != cVar1)) {
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
      if (((cVar1 == '\0') || (cVar1 == '\x02')) && ((pcVar2->entity & 0xffffff) != 5)) {
        n = 0xc2;
      }
      else {
        if (cls == '\x01') goto LAB_1047ab45;
        n = 0xc3;
      }
      diag_error(n,pcVar2);
    }
  }
LAB_1047ab45:
  if ((seg_class != (void *)0x0) && (seg_class != g_name_unnamed)) {
    if (((pcVar2->detail).segment_class == (fe_name *)0x0) ||
       ((pcVar2->detail).segment_class == g_name_unnamed)) {
      (pcVar2->detail).ptr = seg_class;
    }
    if (seg_class != (pcVar2->detail).segment_class) {
      diag_warning(1,0x265,pcVar2);
    }
  }
  if ((((pcVar2->entity & 0xffffff) == 5) && ((g_compile_flags_c4 & 0x20000) != 0)) &&
     ((g_current_function->flags23 & 1) != 0)) {
    pcVar2 = sym_segment_record(g_current_function);
  }
  if ((g_code_seg_name != (void *)0x0) && ((pcVar2->entity & 0xffffff) == 5)) {
    pcVar2 = g_code_seg_name;
  }
  if ((g_data_seg_name != (void *)0x0) && ((pcVar2->entity & 0xffffff) == 2)) {
    pcVar2 = g_data_seg_name;
  }
  if (((pcVar2->x28).bytes.bit_position == '\x02') && (cls == '\0')) {
    (pcVar2->x28).bytes.bit_position = '\0';
  }
  return pcVar2;
}

