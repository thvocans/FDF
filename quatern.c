/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:29:45 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/08 16:29:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

typedef struct s_quat	t_quat;
struct s_quat
{
	float	w;
	float	x;
	float	y;
	float	z;
};

typedef struct s_vec3	t_vec3;
struct s_vec3
{
	float	x;
	float	y;
	float	z;
};

t_quat		quat_rot(float angle, int axe_x, int axe_y, int axe_z)
{
	t_quat q;
	
	angle = angle * (M_PI / 180);
	q.w = cosf(angle / 2);				//floats
	q.x = axe_x * sinf(angle / 2);
	q.y = axe_y * sinf(angle / 2);
	q.z = axe_z * sinf(angle / 2);
	return (q);
}

t_quat		quat_inverse(t_quat q)
{
	q.x *= -1;
	q.y *= -1;
	q.z *= -1;
	return (q);
}

t_quat		quat_mult(t_quat q1, t_quat q2)
{
	t_quat q;

// www.gamedev.net/articles/programming/math-and-physics/quaternion-powers-r1095/
	q.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
	q.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
	q.y = (q1.w * q2.y) + (q1.y * q2.w) + (q1.z * q2.x) - (q1.x * q2.z);
	q.z = (q1.w * q2.z) + (q1.z * q2.w) + (q1.x * q2.y) - (q1.y * q2.x);
	return (q);
}

t_quat		pure_quat(int px_x, int px_y, int px_z) //3 Dim vector to quat
{
	t_quat pure;

	pure.w = 0;		// pure quat : w = 0;
	pure.x = px_x;
	pure.y = px_y;
	pure.z = px_z;
	return (pure);
}

float		vec_dot(t_quat u, t_quat v)
{
//	printf("u	w:%f x:%f y:%f z:%f\n",u.w, u.x, u.y, u.z);
//	printf("v	w:%f x:%f y:%f z:%f\n",v.w, v.x, v.y, v.z);
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_quat	vec_cross(t_quat u, t_quat v)
{
	t_quat out;

	out.w = -1; 				// value for vec3 ??
	out.x = u.y * v.z - u.z * v.y;
//	out.y = (u.x * v.z - u.z * v.x) * -1;
	out.y = u.z * v.x - u.x * v.z;
	out.z = u.x * v.y - u.y * v.x;
	return (out);
}

t_quat		quat_rotation(t_quat vec, t_quat rot)
{
	float	dot1;
	float	dot2;
	t_quat	cross;
	t_quat	out;

	dot1 = vec_dot(vec, rot);
	printf("dot1:	%f\n",dot1);
	dot2 = vec_dot(vec, vec);
	printf("dot2:	%f\n",dot2);
	cross = vec_cross(vec, rot);
	out.x = 2 * dot1 * vec.x + (vec.w * vec.w - dot2) * rot.x\
			+ 2 * vec.w * cross.x;
	out.y = 2 * dot1 * vec.y + (vec.w * vec.w - dot2) * rot.y\
			+ 2 * vec.w * cross.y;
	out.z = 2 * dot1 * vec.z + (vec.w * vec.w - dot2) * rot.z\
			+ 2 * vec.w * cross.z;
	return (out);
}

int main()
{
	t_quat q1;
	t_quat rot;
	t_quat rot2;
	t_quat tot;
	t_quat new;
	t_quat rotinv;

	q1 = pure_quat(10, 10, 2);
	rot = quat_rot(90, 0, 1, 0); // 90 clockwise
//	rot2 = quat_rot(90, 0, 0, 1); // 90 clockwise
	
	rotinv = quat_inverse(rot);

//	new = quat_mult(rot, q1);		//counterclockwise
//	new = quat_mult (new, rotinv);	//counterclockwise
	new = quat_mult(q1, rot);		//clockwise
	new = quat_mult(rotinv, new);	//clockwise
	
	if (q1.z != 0)
	{
		q1.x /= q1.z;
		q1.y /= q1.z;
	}

	printf("q1	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
	printf("rot	w:%f x:%f y:%f z:%f\n",rot.w, rot.x, rot.y, rot.z);
//	printf("q1	w:%f x:%f y:%f z:%f\n",q1.w, q1.x, q1.y, q1.z);
	printf("new	w:%f x:%f y:%f z:%f\n",new.w, new.x, new.y, new.z);
}
