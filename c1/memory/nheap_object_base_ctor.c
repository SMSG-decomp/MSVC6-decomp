void __thiscall nheap_object_base_ctor(c1_pch_segment *obj,int kind,c1_pch_image *owner)

{
  obj->header_offset = 0;
  obj->state = 0;
  obj->kind = kind;
  obj->owner = owner;
  obj->vtbl = (c1_vtbl_1065b500 *)&PTR__purecall_1065b4b4;
  return;
}

