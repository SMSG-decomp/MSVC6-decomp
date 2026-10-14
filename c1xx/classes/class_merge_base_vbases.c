void __cdecl
class_merge_base_vbases
          (c1_vbase_vector *vbases,c1_vbase_vector *base_vbases,c1_symbol *cls,c1_symbol *base_entry
          )

{
  c1_vbase_record *rec;
  short sVar1;
  c1_symbol *cls_00;
  c1_symbol *base_entry_00;
  
  for (sVar1 = 0;
      (base_vbases != (c1_vbase_vector *)0x0 && ((int)sVar1 < (int)(uint)base_vbases->count));
      sVar1 = sVar1 + 1) {
    cls_00 = cls;
    base_entry_00 = base_entry;
    rec = class_vbase_record_inherit(base_vbases->data[sVar1],base_entry,5);
    class_add_vbase_record(vbases,rec,cls_00,base_entry_00);
  }
  return;
}

