int __thiscall mre_note_class_type_index(c1_mre_tracker *tracker,c1_symbol *cls)

{
  int iVar1;
  
  debug_emit_class_type(cls);
  iVar1 = (*tracker->current->file->vtbl->note_class_ti)
                    (((cls->detail).cls)->gm_name_index,((cls->detail).cls)->debug_index);
  return iVar1;
}

