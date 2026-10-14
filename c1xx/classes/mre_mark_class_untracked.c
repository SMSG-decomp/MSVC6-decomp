char __thiscall mre_mark_class_untracked(c1_mre_tracker *tracker,c1_symbol *cls)

{
  char cVar1;
  
  if ((tracker->current->tracked != '\0') && (cls->name != g_name_unnamed)) {
    if (((cls->detail).cls)->gm_name_index == 0) {
      cVar1 = mre_class_name_index(cls);
      if (cVar1 == '\0') {
        return '\0';
      }
    }
    if ((tracker->current->minrebuild_off != 0) || ((((cls->detail).cls)->flags3e & 1) != 0)) {
      ((cls->detail).cls)->flags3e = ((cls->detail).cls)->flags3e | 0x40;
      (*g_pdb_gi->mre_compiler->vtbl->note_untracked_class)(((cls->detail).cls)->gm_name_index);
    }
  }
  return '\x01';
}

