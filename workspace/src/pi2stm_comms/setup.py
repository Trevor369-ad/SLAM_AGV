from setuptools import find_packages, setup

package_name = 'pi2stm_comms'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jowi',
    maintainer_email='owuor.jesse21@students.dkut.ac.ke',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mecanum_controller_interface = pi2stm_comms.mecanum_controller_interface:main'
        ],
    },
)
