void __thiscall type_function_with_return(c1_type *layer,c1_type *this_type)

{
  c1_function_params *pcVar1;
  c1_function_params params;
  
  pcVar1 = (layer->extra).params;
  params.default_count = pcVar1->default_count;
  params.flags = pcVar1->flags;
  params.pad06[0] = pcVar1->pad06[0];
  params.pad06[1] = pcVar1->pad06[1];
  params.defaults = pcVar1->defaults;
  params.list = pcVar1->list;
  params.this_type = this_type;
  pcVar1 = type_function_intern(&params);
  (layer->extra).params = pcVar1;
  return;
}

