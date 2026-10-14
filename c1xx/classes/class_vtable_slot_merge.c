void __cdecl class_vtable_slot_merge(c1_vtable_slot *slot,c1_vtable_slot *other)

{
  c1_symbol *base;
  c1_symbol *cls;
  c1_u32 cVar1;
  short sVar2;
  char cVar3;
  c1_vector *v;
  
  if ((slot->flags & 4) == 0) {
    if (slot->member != other->member) {
      base = g_scope_vector->entries[*(short *)((int)other->member + -2)];
      cls = g_scope_vector->entries[*(short *)((int)slot->member + -2)];
      cVar3 = class_is_same_or_derived(cls,base);
      if (cVar3 != '\0') {
        *(byte *)&slot->flags = (byte)slot->flags & 0xfe | 2;
        return;
      }
      cVar3 = class_is_same_or_derived(base,cls);
      if (cVar3 == '\0') {
        v = vector_new(2,5);
        vector_push(v,slot->member);
        vector_push(v,other->member);
        slot->member = (int *)v;
        *(byte *)&slot->flags = (byte)slot->flags | 4;
        return;
      }
      slot->member = other->member;
      cVar1 = slot->flags;
      slot->path_offset = other->path_offset;
      sVar2 = other->pad0a;
      slot->vbase_index = other->vbase_index;
      slot->pad0a = sVar2;
      *(byte *)&slot->flags = (byte)cVar1 & 0xfe | 2;
      return;
    }
  }
  else if ((other->flags & 1) == 0) {
    cVar3 = vector_contains((c1_vector *)slot->member,other->member);
    if (cVar3 == '\0') {
      vector_push((c1_vector *)slot->member,other->member);
    }
  }
  return;
}

