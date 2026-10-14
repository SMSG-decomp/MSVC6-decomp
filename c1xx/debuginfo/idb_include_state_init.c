c1_idb_include_state * __thiscall idb_include_state_init(c1_idb_include_state *state,byte untracked)

{
  int iVar1;
  uint *src;
  uint *dst;
  
  dst = &(state->pending_class).class_ni;
  (state->regions).data = (c1_idb_region *)0x0;
  (state->regions).capacity = 0;
  (state->regions).count = 0;
  (state->current).signature = 0;
  (state->current).length = -1;
  (state->current).start_line = 0;
  (state->current).line_count = 0;
  (state->current).flags = '\x18';
  ((c1_idb_class_record *)dst)->class_ni = 0;
  (state->pending_class).first_region = 0;
  (state->pending_class).unk08 = 0;
  (state->pending_class).depth = 0;
  (state->pending_class).change = 0;
  ((c1_idb_class_record *)dst)->class_ni = 0;
  state->cursor = 0;
  iVar1 = 5;
  src = &g_idb_empty_class_record.class_ni;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  state->tracker = (c1_mre_file *)0x0;
  state->name_ni = 0;
  state->unk40 = 0;
  state->changed = '\0';
  state->mtime = -1;
  state->untracked = untracked;
  return state;
}

