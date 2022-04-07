#ifndef vtk_exodusII_mangle_h
#define vtk_exodusII_mangle_h

/**
 * Generated using:
 *
 * nm -g lib/libvtkexodusII-9.0.so |   grep -e ' [TDRSB] ' |\
 *   cut -d' ' -f3 | grep -v -e '^_init$' -e '^_fini$' -e '^_edata$' -e '^__bss_start$' -e 'vtkexodusII_' | \
 *   sort | sed -e 's/\(.*\)/#define \1 vtkexodusII_\1/' > /tmp/vtk_exodusII_mangle.h
 */

#define ex_add_attr vtkexodusII_ex_add_attr
#define ex__catstr vtkexodusII_ex__catstr
#define ex__catstr2 vtkexodusII_ex__catstr2
#define ex__check_file_type vtkexodusII_ex__check_file_type
#define ex__check_multiple_open vtkexodusII_ex__check_multiple_open
#define ex__check_valid_file_id vtkexodusII_ex__check_valid_file_id
#define ex__check_version vtkexodusII_ex__check_version
#define ex_close vtkexodusII_ex_close
#define ex__compress_variable vtkexodusII_ex__compress_variable
#define ex__comp_ws vtkexodusII_ex__comp_ws
#define ex_config vtkexodusII_ex_config
#define ex__conv_exit vtkexodusII_ex__conv_exit
#define ex__conv_init vtkexodusII_ex__conv_init
#define ex_copy vtkexodusII_ex_copy
#define ex_copy_string vtkexodusII_ex_copy_string
#define ex_copy_transient vtkexodusII_ex_copy_transient
#define ex_create_group vtkexodusII_ex_create_group
#define ex_create_int vtkexodusII_ex_create_int
#define ex_cvt_nodes_to_sides vtkexodusII_ex_cvt_nodes_to_sides
#define ex__default_max_name_length vtkexodusII_ex__default_max_name_length
#define ex__dim_num_entries_in_object vtkexodusII_ex__dim_num_entries_in_object
#define ex__dim_num_objects vtkexodusII_ex__dim_num_objects
#define ex_err vtkexodusII_ex_err
#define ex_err_fn vtkexodusII_ex_err_fn
#define ex_errval vtkexodusII_ex_errval
#define exerrval_get vtkexodusII_exerrval_get
#define EX_errval_key_g vtkexodusII_EX_errval_key_g
#define ex__find_file_item vtkexodusII_ex__find_file_item
#define EX_first_init_g vtkexodusII_EX_first_init_g
#define EX_g vtkexodusII_EX_g
#define ex_get_all_times vtkexodusII_ex_get_all_times
#define ex_get_assemblies vtkexodusII_ex_get_assemblies
#define ex_get_assembly vtkexodusII_ex_get_assembly
#define ex_get_attr vtkexodusII_ex_get_attr
#define ex_get_attribute vtkexodusII_ex_get_attribute
#define ex_get_attribute_count vtkexodusII_ex_get_attribute_count
#define ex_get_attribute_param vtkexodusII_ex_get_attribute_param
#define ex_get_attributes vtkexodusII_ex_get_attributes
#define ex_get_attr_names vtkexodusII_ex_get_attr_names
#define ex_get_attr_param vtkexodusII_ex_get_attr_param
#define ex_get_blob vtkexodusII_ex_get_blob
#define ex_get_blobs vtkexodusII_ex_get_blobs
#define ex_get_block vtkexodusII_ex_get_block
#define ex__get_block_param vtkexodusII_ex__get_block_param
#define ex_get_block_param vtkexodusII_ex_get_block_param
#define ex_get_block_params vtkexodusII_ex_get_block_params
#define ex_get_cmap_params vtkexodusII_ex_get_cmap_params
#define ex_get_concat_node_sets vtkexodusII_ex_get_concat_node_sets
#define ex_get_concat_sets vtkexodusII_ex_get_concat_sets
#define ex_get_concat_side_set_node_count vtkexodusII_ex_get_concat_side_set_node_count
#define ex_get_concat_side_sets vtkexodusII_ex_get_concat_side_sets
#define ex_get_conn vtkexodusII_ex_get_conn
#define ex_get_coord vtkexodusII_ex_get_coord
#define ex_get_coordinate_frames vtkexodusII_ex_get_coordinate_frames
#define ex_get_coord_names vtkexodusII_ex_get_coord_names
#define ex__get_counter_list vtkexodusII_ex__get_counter_list
#define ex__get_cpu_ws vtkexodusII_ex__get_cpu_ws
#define ex__get_dimension vtkexodusII_ex__get_dimension
#define ex_get_eb_info_global vtkexodusII_ex_get_eb_info_global
#define ex_get_elem_attr vtkexodusII_ex_get_elem_attr
#define ex_get_elem_attr_names vtkexodusII_ex_get_elem_attr_names
#define ex_get_elem_blk_ids vtkexodusII_ex_get_elem_blk_ids
#define ex_get_elem_block vtkexodusII_ex_get_elem_block
#define ex_get_elem_cmap vtkexodusII_ex_get_elem_cmap
#define ex_get_elem_conn vtkexodusII_ex_get_elem_conn
#define ex_get_elem_map vtkexodusII_ex_get_elem_map
#define ex_get_elem_num_map vtkexodusII_ex_get_elem_num_map
#define ex_get_elem_type vtkexodusII_ex_get_elem_type
#define ex_get_elem_var vtkexodusII_ex_get_elem_var
#define ex_get_elem_var_tab vtkexodusII_ex_get_elem_var_tab
#define ex_get_elem_var_time vtkexodusII_ex_get_elem_var_time
#define ex_get_entity_count_per_polyhedra vtkexodusII_ex_get_entity_count_per_polyhedra
#define ex_get_err vtkexodusII_ex_get_err
#define ex__get_file_item vtkexodusII_ex__get_file_item
#define ex__get_file_type vtkexodusII_ex__get_file_type
#define ex__get_glob_vars vtkexodusII_ex__get_glob_vars
#define ex_get_glob_vars vtkexodusII_ex_get_glob_vars
#define ex__get_glob_var_time vtkexodusII_ex__get_glob_var_time
#define ex_get_glob_var_time vtkexodusII_ex_get_glob_var_time
#define ex_get_group_id vtkexodusII_ex_get_group_id
#define ex_get_group_ids vtkexodusII_ex_get_group_ids
#define ex_get_id_map vtkexodusII_ex_get_id_map
#define ex_get_ids vtkexodusII_ex_get_ids
#define ex_get_idx vtkexodusII_ex_get_idx
#define ex_get_info vtkexodusII_ex_get_info
#define ex_get_init vtkexodusII_ex_get_init
#define ex_get_init_ext vtkexodusII_ex_get_init_ext
#define ex_get_init_global vtkexodusII_ex_get_init_global
#define ex_get_init_info vtkexodusII_ex_get_init_info
#define ex_get_loadbal_param vtkexodusII_ex_get_loadbal_param
#define ex_get_map vtkexodusII_ex_get_map
#define ex_get_map_param vtkexodusII_ex_get_map_param
#define ex__get_name vtkexodusII_ex__get_name
#define ex_get_name vtkexodusII_ex_get_name
#define ex__get_names vtkexodusII_ex__get_names
#define ex_get_names vtkexodusII_ex_get_names
#define ex_get_n_attr vtkexodusII_ex_get_n_attr
#define ex_get_n_conn vtkexodusII_ex_get_n_conn
#define ex_get_n_coord vtkexodusII_ex_get_n_coord
#define ex_get_n_elem_attr vtkexodusII_ex_get_n_elem_attr
#define ex_get_n_elem_conn vtkexodusII_ex_get_n_elem_conn
#define ex_get_n_elem_num_map vtkexodusII_ex_get_n_elem_num_map
#define ex_get_n_elem_var vtkexodusII_ex_get_n_elem_var
#define ex_get_n_nodal_var vtkexodusII_ex_get_n_nodal_var
#define ex_get_n_node_num_map vtkexodusII_ex_get_n_node_num_map
#define ex_get_n_node_set vtkexodusII_ex_get_n_node_set
#define ex_get_n_node_set_df vtkexodusII_ex_get_n_node_set_df
#define ex__get_nodal_var vtkexodusII_ex__get_nodal_var
#define ex_get_nodal_var vtkexodusII_ex_get_nodal_var
#define ex__get_nodal_var_time vtkexodusII_ex__get_nodal_var_time
#define ex_get_nodal_var_time vtkexodusII_ex_get_nodal_var_time
#define ex_get_node_cmap vtkexodusII_ex_get_node_cmap
#define ex_get_node_map vtkexodusII_ex_get_node_map
#define ex_get_node_num_map vtkexodusII_ex_get_node_num_map
#define ex_get_node_set vtkexodusII_ex_get_node_set
#define ex_get_node_set_dist_fact vtkexodusII_ex_get_node_set_dist_fact
#define ex_get_node_set_ids vtkexodusII_ex_get_node_set_ids
#define ex_get_node_set_param vtkexodusII_ex_get_node_set_param
#define ex_get_n_one_attr vtkexodusII_ex_get_n_one_attr
#define ex_get_nset_var vtkexodusII_ex_get_nset_var
#define ex_get_nset_var_tab vtkexodusII_ex_get_nset_var_tab
#define ex_get_n_side_set vtkexodusII_ex_get_n_side_set
#define ex_get_n_side_set_df vtkexodusII_ex_get_n_side_set_df
#define ex_get_ns_param_global vtkexodusII_ex_get_ns_param_global
#define ex_get_num_map vtkexodusII_ex_get_num_map
#define ex_get_num_props vtkexodusII_ex_get_num_props
#define ex_get_n_var vtkexodusII_ex_get_n_var
#define ex_get_object_truth_vector vtkexodusII_ex_get_object_truth_vector
#define ex_get_one_attr vtkexodusII_ex_get_one_attr
#define ex_get_one_elem_attr vtkexodusII_ex_get_one_elem_attr
#define ex_get_partial_attr vtkexodusII_ex_get_partial_attr
#define ex_get_partial_conn vtkexodusII_ex_get_partial_conn
#define ex_get_partial_coord vtkexodusII_ex_get_partial_coord
#define ex_get_partial_coord_component vtkexodusII_ex_get_partial_coord_component
#define ex_get_partial_elem_attr vtkexodusII_ex_get_partial_elem_attr
#define ex_get_partial_elem_conn vtkexodusII_ex_get_partial_elem_conn
#define ex_get_partial_elem_map vtkexodusII_ex_get_partial_elem_map
#define ex_get_partial_elem_num_map vtkexodusII_ex_get_partial_elem_num_map
#define ex_get_partial_elem_var vtkexodusII_ex_get_partial_elem_var
#define ex_get_partial_id_map vtkexodusII_ex_get_partial_id_map
#define ex__get_partial_nodal_var vtkexodusII_ex__get_partial_nodal_var
#define ex_get_partial_nodal_var vtkexodusII_ex_get_partial_nodal_var
#define ex_get_partial_node_num_map vtkexodusII_ex_get_partial_node_num_map
#define ex_get_partial_node_set vtkexodusII_ex_get_partial_node_set
#define ex_get_partial_node_set_df vtkexodusII_ex_get_partial_node_set_df
#define ex_get_partial_num_map vtkexodusII_ex_get_partial_num_map
#define ex_get_partial_one_attr vtkexodusII_ex_get_partial_one_attr
#define ex_get_partial_set vtkexodusII_ex_get_partial_set
#define ex_get_partial_set_dist_fact vtkexodusII_ex_get_partial_set_dist_fact
#define ex_get_partial_side_set vtkexodusII_ex_get_partial_side_set
#define ex_get_partial_side_set_df vtkexodusII_ex_get_partial_side_set_df
#define ex_get_partial_var vtkexodusII_ex_get_partial_var
#define ex_get_processor_elem_maps vtkexodusII_ex_get_processor_elem_maps
#define ex_get_processor_node_maps vtkexodusII_ex_get_processor_node_maps
#define ex_get_prop vtkexodusII_ex_get_prop
#define ex_get_prop_array vtkexodusII_ex_get_prop_array
#define ex_get_prop_names vtkexodusII_ex_get_prop_names
#define ex_get_qa vtkexodusII_ex_get_qa
#define ex_get_reduction_variable_names vtkexodusII_ex_get_reduction_variable_names
#define ex_get_reduction_variable_param vtkexodusII_ex_get_reduction_variable_param
#define ex_get_reduction_vars vtkexodusII_ex_get_reduction_vars
#define ex_get_set vtkexodusII_ex_get_set
#define ex_get_set_dist_fact vtkexodusII_ex_get_set_dist_fact
#define ex_get_set_param vtkexodusII_ex_get_set_param
#define ex_get_sets vtkexodusII_ex_get_sets
#define ex_get_side_set vtkexodusII_ex_get_side_set
#define ex_get_side_set_dist_fact vtkexodusII_ex_get_side_set_dist_fact
#define ex_get_side_set_ids vtkexodusII_ex_get_side_set_ids
#define ex_get_side_set_node_count vtkexodusII_ex_get_side_set_node_count
#define ex_get_side_set_node_list vtkexodusII_ex_get_side_set_node_list
#define ex_get_side_set_node_list_len vtkexodusII_ex_get_side_set_node_list_len
#define ex_get_side_set_param vtkexodusII_ex_get_side_set_param
#define ex_get_sset_var vtkexodusII_ex_get_sset_var
#define ex_get_sset_var_tab vtkexodusII_ex_get_sset_var_tab
#define ex_get_ss_param_global vtkexodusII_ex_get_ss_param_global
#define ex__get_stat_ptr vtkexodusII_ex__get_stat_ptr
#define ex_get_time vtkexodusII_ex_get_time
#define ex_get_truth_table vtkexodusII_ex_get_truth_table
#define ex_get_var vtkexodusII_ex_get_var
#define ex_get_variable_name vtkexodusII_ex_get_variable_name
#define ex_get_variable_names vtkexodusII_ex_get_variable_names
#define ex_get_variable_param vtkexodusII_ex_get_variable_param
#define ex_get_var_name vtkexodusII_ex_get_var_name
#define ex_get_var_names vtkexodusII_ex_get_var_names
#define ex_get_var_param vtkexodusII_ex_get_var_param
#define ex_get_var_tab vtkexodusII_ex_get_var_tab
#define ex_get_var_time vtkexodusII_ex_get_var_time
#define ex__handle_mode vtkexodusII_ex__handle_mode
#define ex_header_size vtkexodusII_ex_header_size
#define ex__id_lkup vtkexodusII_ex__id_lkup
#define ex__inc_file_item vtkexodusII_ex__inc_file_item
#define ex_inquire vtkexodusII_ex_inquire
#define ex_inquire_int vtkexodusII_ex_inquire_int
#define ex_int64_status vtkexodusII_ex_int64_status
#define ex_int_write_conn vtkexodusII_ex_int_write_conn
#define ex__iqsort vtkexodusII_ex__iqsort
#define ex__iqsort64 vtkexodusII_ex__iqsort64
#define ex__is_parallel vtkexodusII_ex__is_parallel
#define ex_large_model vtkexodusII_ex_large_model
#define ex__leavedef vtkexodusII_ex__leavedef
#define ex__mutex_lock vtkexodusII_ex__mutex_lock
#define ex__mutex_unlock vtkexodusII_ex__mutex_unlock
#define ex__name_of_map vtkexodusII_ex__name_of_map
#define ex_name_of_object vtkexodusII_ex_name_of_object
#define ex__name_red_var_of_object vtkexodusII_ex__name_red_var_of_object
#define ex__name_var_of_object vtkexodusII_ex__name_var_of_object
#define exodus_unused_symbol_dummy_ex_create_par vtkexodusII_exodus_unused_symbol_dummy_ex_create_par
#define exodus_unused_symbol_dummy_ex_open_par vtkexodusII_exodus_unused_symbol_dummy_ex_open_par
#define exoII_ass vtkexodusII_exoII_ass
#define exoII_eb vtkexodusII_exoII_eb
#define exoII_ed vtkexodusII_exoII_ed
#define exoII_edm vtkexodusII_exoII_edm
#define exoII_els vtkexodusII_exoII_els
#define exoII_em vtkexodusII_exoII_em
#define exoII_es vtkexodusII_exoII_es
#define exoII_fa vtkexodusII_exoII_fa
#define exoII_fam vtkexodusII_exoII_fam
#define exoII_fs vtkexodusII_exoII_fs
#define exoII_nm vtkexodusII_exoII_nm
#define exoII_ns vtkexodusII_exoII_ns
#define exoII_ss vtkexodusII_exoII_ss
#define ex_open_int vtkexodusII_ex_open_int
#define ex_opts vtkexodusII_ex_opts
#define exoptval vtkexodusII_exoptval
#define ex__populate_header vtkexodusII_ex__populate_header
#define ex_print_config vtkexodusII_ex_print_config
#define ex__pthread_first_thread_init vtkexodusII_ex__pthread_first_thread_init
#define ex_put_all_var_param vtkexodusII_ex_put_all_var_param
#define ex_put_all_var_param_ext vtkexodusII_ex_put_all_var_param_ext
#define ex_put_assemblies vtkexodusII_ex_put_assemblies
#define ex_put_attr vtkexodusII_ex_put_attr
#define ex_put_attribute vtkexodusII_ex_put_attribute
#define ex_put_attributes vtkexodusII_ex_put_attributes
#define ex_put_attr_names vtkexodusII_ex_put_attr_names
#define ex_put_attr_param vtkexodusII_ex_put_attr_param
#define ex_put_blobs vtkexodusII_ex_put_blobs
#define ex_put_block vtkexodusII_ex_put_block
#define ex_put_block_param vtkexodusII_ex_put_block_param
#define ex_put_block_params vtkexodusII_ex_put_block_params
#define ex_put_cmap_params vtkexodusII_ex_put_cmap_params
#define ex_put_cmap_params_cc vtkexodusII_ex_put_cmap_params_cc
#define ex_put_concat_all_blocks vtkexodusII_ex_put_concat_all_blocks
#define ex_put_concat_elem_block vtkexodusII_ex_put_concat_elem_block
#define ex_put_concat_node_sets vtkexodusII_ex_put_concat_node_sets
#define ex_put_concat_sets vtkexodusII_ex_put_concat_sets
#define ex_put_concat_side_sets vtkexodusII_ex_put_concat_side_sets
#define ex_put_concat_var_param vtkexodusII_ex_put_concat_var_param
#define ex_put_conn vtkexodusII_ex_put_conn
#define ex_put_coord vtkexodusII_ex_put_coord
#define ex_put_coordinate_frames vtkexodusII_ex_put_coordinate_frames
#define ex_put_coord_names vtkexodusII_ex_put_coord_names
#define ex_put_double_attribute vtkexodusII_ex_put_double_attribute
#define ex_put_eb_info_global vtkexodusII_ex_put_eb_info_global
#define ex_put_elem_attr vtkexodusII_ex_put_elem_attr
#define ex_put_elem_attr_names vtkexodusII_ex_put_elem_attr_names
#define ex_put_elem_block vtkexodusII_ex_put_elem_block
#define ex_put_elem_cmap vtkexodusII_ex_put_elem_cmap
#define ex_put_elem_conn vtkexodusII_ex_put_elem_conn
#define ex_put_elem_map vtkexodusII_ex_put_elem_map
#define ex_put_elem_num_map vtkexodusII_ex_put_elem_num_map
#define ex_put_elem_var vtkexodusII_ex_put_elem_var
#define ex_put_elem_var_slab vtkexodusII_ex_put_elem_var_slab
#define ex_put_elem_var_tab vtkexodusII_ex_put_elem_var_tab
#define ex_put_entity_count_per_polyhedra vtkexodusII_ex_put_entity_count_per_polyhedra
#define ex_put_glob_vars vtkexodusII_ex_put_glob_vars
#define ex__put_homogenous_block_params vtkexodusII_ex__put_homogenous_block_params
#define ex_put_id_map vtkexodusII_ex_put_id_map
#define ex_put_info vtkexodusII_ex_put_info
#define ex_put_init vtkexodusII_ex_put_init
#define ex_put_init_ext vtkexodusII_ex_put_init_ext
#define ex_put_init_global vtkexodusII_ex_put_init_global
#define ex_put_init_info vtkexodusII_ex_put_init_info
#define ex_put_integer_attribute vtkexodusII_ex_put_integer_attribute
#define ex_put_loadbal_param vtkexodusII_ex_put_loadbal_param
#define ex_put_loadbal_param_cc vtkexodusII_ex_put_loadbal_param_cc
#define ex_put_map vtkexodusII_ex_put_map
#define ex_put_map_param vtkexodusII_ex_put_map_param
#define ex__put_name vtkexodusII_ex__put_name
#define ex_put_name vtkexodusII_ex_put_name
#define ex__put_names vtkexodusII_ex__put_names
#define ex_put_names vtkexodusII_ex_put_names
#define ex_put_n_attr vtkexodusII_ex_put_n_attr
#define ex_put_n_coord vtkexodusII_ex_put_n_coord
#define ex_put_n_elem_attr vtkexodusII_ex_put_n_elem_attr
#define ex_put_n_elem_conn vtkexodusII_ex_put_n_elem_conn
#define ex_put_n_elem_num_map vtkexodusII_ex_put_n_elem_num_map
#define ex__put_nemesis_version vtkexodusII_ex__put_nemesis_version
#define ex_put_n_nodal_var vtkexodusII_ex_put_n_nodal_var
#define ex_put_n_node_num_map vtkexodusII_ex_put_n_node_num_map
#define ex_put_n_node_set vtkexodusII_ex_put_n_node_set
#define ex_put_n_node_set_df vtkexodusII_ex_put_n_node_set_df
#define ex__put_nodal_var vtkexodusII_ex__put_nodal_var
#define ex_put_nodal_var vtkexodusII_ex_put_nodal_var
#define ex_put_nodal_var_slab vtkexodusII_ex_put_nodal_var_slab
#define ex_put_node_cmap vtkexodusII_ex_put_node_cmap
#define ex_put_node_map vtkexodusII_ex_put_node_map
#define ex_put_node_num_map vtkexodusII_ex_put_node_num_map
#define ex_put_node_set vtkexodusII_ex_put_node_set
#define ex_put_node_set_dist_fact vtkexodusII_ex_put_node_set_dist_fact
#define ex_put_node_set_param vtkexodusII_ex_put_node_set_param
#define ex_put_n_one_attr vtkexodusII_ex_put_n_one_attr
#define ex_put_nset_var vtkexodusII_ex_put_nset_var
#define ex_put_nset_var_tab vtkexodusII_ex_put_nset_var_tab
#define ex_put_n_side_set vtkexodusII_ex_put_n_side_set
#define ex_put_n_side_set_df vtkexodusII_ex_put_n_side_set_df
#define ex_put_ns_param_global vtkexodusII_ex_put_ns_param_global
#define ex_put_num_map vtkexodusII_ex_put_num_map
#define ex_put_n_var vtkexodusII_ex_put_n_var
#define ex_put_one_attr vtkexodusII_ex_put_one_attr
#define ex_put_one_elem_attr vtkexodusII_ex_put_one_elem_attr
#define ex_put_partial_attr vtkexodusII_ex_put_partial_attr
#define ex_put_partial_conn vtkexodusII_ex_put_partial_conn
#define ex_put_partial_coord vtkexodusII_ex_put_partial_coord
#define ex_put_partial_coord_component vtkexodusII_ex_put_partial_coord_component
#define ex_put_partial_elem_attr vtkexodusII_ex_put_partial_elem_attr
#define ex_put_partial_elem_conn vtkexodusII_ex_put_partial_elem_conn
#define ex_put_partial_elem_map vtkexodusII_ex_put_partial_elem_map
#define ex_put_partial_elem_num_map vtkexodusII_ex_put_partial_elem_num_map
#define ex_put_partial_id_map vtkexodusII_ex_put_partial_id_map
#define ex__put_partial_nodal_var vtkexodusII_ex__put_partial_nodal_var
#define ex_put_partial_nodal_var vtkexodusII_ex_put_partial_nodal_var
#define ex_put_partial_node_num_map vtkexodusII_ex_put_partial_node_num_map
#define ex_put_partial_node_set vtkexodusII_ex_put_partial_node_set
#define ex_put_partial_node_set_df vtkexodusII_ex_put_partial_node_set_df
#define ex_put_partial_num_map vtkexodusII_ex_put_partial_num_map
#define ex_put_partial_one_attr vtkexodusII_ex_put_partial_one_attr
#define ex_put_partial_set vtkexodusII_ex_put_partial_set
#define ex_put_partial_set_dist_fact vtkexodusII_ex_put_partial_set_dist_fact
#define ex_put_partial_side_set vtkexodusII_ex_put_partial_side_set
#define ex_put_partial_side_set_df vtkexodusII_ex_put_partial_side_set_df
#define ex_put_partial_var vtkexodusII_ex_put_partial_var
#define ex_put_processor_elem_maps vtkexodusII_ex_put_processor_elem_maps
#define ex_put_processor_node_maps vtkexodusII_ex_put_processor_node_maps
#define ex_put_prop vtkexodusII_ex_put_prop
#define ex_put_prop_array vtkexodusII_ex_put_prop_array
#define ex_put_prop_names vtkexodusII_ex_put_prop_names
#define ex_put_qa vtkexodusII_ex_put_qa
#define ex_put_reduction_variable_names vtkexodusII_ex_put_reduction_variable_names
#define ex_put_reduction_variable_param vtkexodusII_ex_put_reduction_variable_param
#define ex_put_reduction_vars vtkexodusII_ex_put_reduction_vars
#define ex_put_set vtkexodusII_ex_put_set
#define ex_put_set_dist_fact vtkexodusII_ex_put_set_dist_fact
#define ex_put_set_param vtkexodusII_ex_put_set_param
#define ex_put_sets vtkexodusII_ex_put_sets
#define ex_put_side_set vtkexodusII_ex_put_side_set
#define ex_put_side_set_dist_fact vtkexodusII_ex_put_side_set_dist_fact
#define ex_put_side_set_param vtkexodusII_ex_put_side_set_param
#define ex_put_sset_var vtkexodusII_ex_put_sset_var
#define ex_put_sset_var_tab vtkexodusII_ex_put_sset_var_tab
#define ex_put_ss_param_global vtkexodusII_ex_put_ss_param_global
#define ex_put_text_attribute vtkexodusII_ex_put_text_attribute
#define ex_put_time vtkexodusII_ex_put_time
#define ex_put_truth_table vtkexodusII_ex_put_truth_table
#define ex_put_var vtkexodusII_ex_put_var
#define ex_put_variable_name vtkexodusII_ex_put_variable_name
#define ex_put_variable_names vtkexodusII_ex_put_variable_names
#define ex_put_variable_param vtkexodusII_ex_put_variable_param
#define ex_put_var_name vtkexodusII_ex_put_var_name
#define ex_put_var_names vtkexodusII_ex_put_var_names
#define ex_put_var_param vtkexodusII_ex_put_var_param
#define ex_put_var_tab vtkexodusII_ex_put_var_tab
#define ex__reset_error_status vtkexodusII_ex__reset_error_status
#define ex__rm_file_item vtkexodusII_ex__rm_file_item
#define ex__rm_stat_ptr vtkexodusII_ex__rm_stat_ptr
#define ex__set_compact_storage vtkexodusII_ex__set_compact_storage
#define ex_set_err vtkexodusII_ex_set_err
#define ex_set_int64_status vtkexodusII_ex_set_int64_status
#define ex_set_max_name_length vtkexodusII_ex_set_max_name_length
#define ex_set_option vtkexodusII_ex_set_option
#define ex_set_parallel vtkexodusII_ex_set_parallel
#define ex_strerror vtkexodusII_ex_strerror
#define ex__trim vtkexodusII_ex__trim
#define ex_update vtkexodusII_ex_update
#define ex__update_max_name_length vtkexodusII_ex__update_max_name_length
#define ex_var_type_to_ex_entity_type vtkexodusII_ex_var_type_to_ex_entity_type
#define nc_flt_code vtkexodusII_nc_flt_code
#define ne__check_file_version vtkexodusII_ne__check_file_version
#define ne__id_lkup vtkexodusII_ne__id_lkup
#define ne_ret_string vtkexodusII_ne_ret_string

#endif
